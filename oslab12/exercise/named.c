#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>

sem_t mutex;

int count = 0;
void inc(void);
void dec(void);

int main(void){
    mutex = *sem_open("/mysem", O_CREAT, 0644, 1);

    int i = 0;
    pthread_t id[4];
    pthread_create(&id[0], NULL, (void *)inc, NULL);
    pthread_create(&id[1], NULL, (void *)dec, NULL);
    pthread_create(&id[2], NULL, (void *)inc, NULL);
    pthread_create(&id[3], NULL, (void *)dec, NULL);
    for(i = 0; i < 4; i++){
        pthread_join(id[i], NULL);
    }
    printf("count = %d\n", count);
    sem_unlink("/mysem");
    pthread_exit(NULL);
    return 0;
}

void inc(void){
    int i = 0;
    sem_wait(&mutex);
    for(i = 0; i < 5; i++){
        count++;
        printf("count: %d\n", count);
    }
    sem_post(&mutex);
}

void dec(void){
    int i = 0;
    sem_wait(&mutex);
    for(i = 0; i < 5; i++){
        count--;
        printf("count: %d\n", count);
    }
    sem_post(&mutex);
}