#include<signal.h>
#include<stdio.h>
#include<unistd.h>

// use system call kill to send signal to process
int main()
{
    int pid;
    pid = fork();
    if(pid != 0){
        printf("%d\n", pid);
        sleep(1);
        kill(pid, SIGTERM);
        printf("Child process is killed\n");
    }
    else{
        while (1)
        {
            /* code */
            sleep(1);
        }
    }
}