#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int pid;
    pid = fork();
    if(pid != 0){
        printf("%d\n", pid);
        wait(NULL);
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