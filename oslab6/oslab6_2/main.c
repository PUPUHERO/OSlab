#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t child_pid_1, child_pid_2, child_pid_3, child_pid_4;

    child_pid_1 = fork();
    switch (child_pid_1)
    {
    case -1:
        perror("fork");
        break;
    case 0:
        printf("I am child process B\n");
        child_pid_2 = fork();
        switch (child_pid_2)
        {
        case -1:
            perror("fork");
            break;
        case 0:
            printf("I am child process C\n");
            break; 
        default:
            wait(NULL);
            // printf("I am child process D\n");
            break;
        }
        break;
    default:
        wait(NULL);
        child_pid_3 = fork();
        switch (child_pid_3)
        {
        case -1:
            perror("fork");
            break;
        case 0:
            printf("I am child process D\n");
        default:
            wait(NULL);
            child_pid_4 = fork();
            switch (child_pid_4)
            {
            case -1:
                perror("fork");
                break;
            case 0:
                printf("I am child process E\n");
            default:
                break;
            }
            break;
        }
        break;
    }
    
}