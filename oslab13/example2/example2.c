#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static int available_resources = 0;

static void *producer(void *arg);

int main(int argc, char *argv[]){
    pthread_t tid;
    int s, j;
    int total_required, num_consumed;

    bool done;
    time_t t;
    t = time(NULL);

    total_required = 0;
    for(j = 1; j < argc; j++){
        total_required += atoi(argv[j]);
        s = pthread_create(&tid, NULL, producer, argv[j]);
        if (s != 0){
            perror("pthread_create");
            exit(1);
        }        
    }

    num_consumed = 0;
    done = false;

    for(;;){
        pthread_mutex_lock(&mutex);

        if(available_resources == 0){
            printf("wait available = 0, t = %ld\n", time(NULL) - t);
        }
        while (available_resources > 0){
            available_resources--;
            num_consumed++;
            printf("T= %ld: numConsumed %d\n", (long)(time(NULL) - t), num_consumed);
            done = num_consumed >= total_required;
        }
        pthread_mutex_unlock(&mutex);
        if (done)
        {
            break;
        }
    }
    s = pthread_mutex_destroy(&mutex);
    return 0;
}

static void *producer(void *arg){
    int *value = (int *) arg;
    int s, i;

    for(i = 0; i < *value; i++){
        sleep(1);
        pthread_mutex_lock(&mutex);
        available_resources++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
