#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
static pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;
static pthread_cond_t cond3 = PTHREAD_COND_INITIALIZER;

static int printingNumber = 1;

static void *print1_thread(void *arg);
static void *print3_thread(void *arg);
static void *print5_thread(void *arg);

int main(int argc, char *argv[]){
    pthread_t t1, t2, t3;
    int s;

    s = pthread_create(&t1, NULL, print1_thread, NULL);
    if (s != 0){
        perror("pthread_create");
        exit(1);
    }
    s = pthread_create(&t2, NULL, print3_thread, NULL);
    if (s != 0){
        perror("pthread_create");
        exit(1);
    }
    s = pthread_create(&t3, NULL, print5_thread, NULL);
    if (s != 0){
        perror("pthread_create");
        exit(1);
    }

    pthread_cond_signal(&cond);

    s = pthread_join(t1, NULL);
    if (s != 0){
        perror("pthread_join");
        exit(1);
    }
    s = pthread_join(t2, NULL);
    if (s != 0){
        perror("pthread_join");
        exit(1);
    }
    s = pthread_join(t3, NULL);
    if (s != 0){
        perror("pthread_join");
        exit(1);
    }

    return 0;
}

static void *print1_thread(void *arg){
    while (1)
    {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond, &mutex);
        printf("1 ");
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond2);
    }
    return NULL;
}

static void *print3_thread(void *arg){
    while (1) {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond2, &mutex);
        printf("3 ");
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond3);
    }
    return NULL;
}

static void *print5_thread(void *arg){
    while (1) {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond3, &mutex);
        printf("5 ");
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
    }
    return NULL;
}


