#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<mqueue.h>

#define MQNAME "/myMsgQueue"
#define MAX_MSG_SIZE 1000

void *send_thread(void *arg) {
    mqd_t mqd = mq_open(MQNAME, O_WRONLY | O_CREAT, 0644, NULL);
    if (mqd == -1){
        perror("Failed to open message queue");
        return 1;
    }
    
    while (1)
    {
        char buffer[MAX_MSG_SIZE];
        for (int i = 0; i < MAX_MSG_SIZE; i++)
            buffer[i] = '\0';

        printf("Send to receiver: \n");
        printf("> ");
        fgets(buffer, MAX_MSG_SIZE, stdin);
        int send = mq_send(mqd, buffer, strlen(buffer), 0);
        if (send == -1){
            perror("Failed to send message");
            return 1;
        }
        if(strcmp(buffer, "exit\n") == 0){
            break;
        }
    }
    pthread_exit(NULL);
    return NULL;
}

void *receive_thread(void *arg) {
    mqd_t mqd = mq_open(MQNAME, O_RDONLY | O_CREAT, 0644, NULL);
    if (mqd == -1)
    {
        perror("Failed to open message queue");
        return 1;
    }

    while (1)
    {
        char buffer[MAX_MSG_SIZE];
        ssize_t msg_size = mq_receive(mqd, buffer, 8192, NULL);
        if (msg_size == -1)
        {
            perror("Failed to receive message");
            return 1;
        }
        // "\r\n\?" for WSL
        if(strcmp(buffer, "exit\n") == 0 || strcmp(buffer, "exit\r\n\?") == 0){
            printf("Exiting receiver...\n");
            break;
        }
        printf("Received: %s", buffer);       
    }

    int close = mq_close(mqd);
    if (close == -1)
    {
        perror("Failed to close message queue");
        return 1;
    }

    int unlink = mq_unlink(MQNAME);
    if (unlink == -1)
    {
        perror("Failed to unlink message queue");
        return 1;
    }
    
    pthread_exit(NULL);
    return NULL;
}

int main() {
    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, send_thread, NULL);
    pthread_join(tid1, NULL);

    pthread_create(&tid2, NULL, receive_thread, NULL);    
    pthread_join(tid2, NULL);

    return 0;
}
