#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>

sem_t *mutex;

int main(){
    mutex = sem_open("/mysem", O_CREAT, 0644, 1);
    sem_wait(mutex);
    printf("\nWaiting..\n");

    sleep(1);
    printf("Sleeping...\n");

    sem_post(mutex);
    printf("Done.\n");
    sem_unlink("/mysem");
    return 0;
}