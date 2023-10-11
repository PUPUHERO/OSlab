#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void print_process_info(char *process_name){
    printf("I am %s process\n", process_name);
    printf("pid: %d   parent id: %d\n", getpid(), getppid());
}

int main(){
    pid_t child_pid_1, child_pid_2, child_pid_3, child_pid_4;

    child_pid_1 = fork();
    switch (child_pid_1)
    {
    case -1:
        perror("fork");
        break;
    case 0:
        print_process_info("B");
        child_pid_2 = fork();
        switch (child_pid_2)
        {
        case -1:
            perror("fork");
            break;
        case 0:
            print_process_info("C");
            break; 
        default:
            wait(NULL);
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
            print_process_info("E");
            break;
        default:
            wait(NULL);
            child_pid_4 = fork();
            switch (child_pid_4)
            {
            case -1:
                perror("fork");
                break;
            case 0:
                print_process_info("D");
                break;
            default:
                wait(NULL);
                print_process_info("A");
                break;
            }
            break;
        }
        break;
    }
    
}