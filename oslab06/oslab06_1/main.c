#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int int_global = 10;

int main(){
    pid_t child_pid;

    int int_local = 10;

    child_pid = fork();
    

    switch (child_pid)
    {
    case -1:
        perror("fork");
        break;
    // child process
    case 0:
        printf("I am child process\n");
        printf("pid: %d   parent id: %d\n", getpid(), getppid());
        printf("global = %d, local = %d\n", int_global, int_local);
        int_global++;
        int_local++;
        printf("Finally print : pid = %d, parent id = %d, global = %d, local = %d\n", getpid(), getppid(), int_global, int_local);
        break;
    default:
        wait(NULL);
        printf("I am parent process\n");
        printf("pid: %d   parent id: %d\n", getpid(), getppid());
        printf("global = %d, local = %d\n", int_global, int_local);
        printf("Finally print : pid = %d, parent id = %d, global = %d, local = %d\n", getpid(), getppid(), int_global, int_local);
        break;
    }

}