#include<fcntl.h>
#include<mqueue.h>
#include<stdio.h>
#include<string.h>

#define MQNAME "/myMsgQueue"
#define MAX_MSG_SIZE 1000

int main(){
    mqd_t mqd = mq_open(MQNAME, O_RDONLY, 0644, NULL);
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
        if(strcmp(buffer, "exit\n") == 0){
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
    
    return 0;
}




