#include<fcntl.h>
#include<mqueue.h>
#include<stdio.h>
#include<string.h>

#define MQNAME "/myMsgQueue"
#define MAX_MSG_SIZE 1000

int main(){
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
    return 0;
}

