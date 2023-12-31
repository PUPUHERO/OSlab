#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static int glob = 0;
static void *threadFunc(void *arg);

int main(int argc, char *argv[]){
    pthread_t t1, t2;
    int loops, s;

    loops = (argc > 1) ? atoi(argv[1]) : 10000000;

    s = pthread_create(&t1, NULL, threadFunc, &loops);
    if(s != 0){
        perror("pthread_create");
        exit(1);
    }
    s = pthread_create(&t2, NULL, threadFunc, &loops);
    if(s != 0){
        perror("pthread_create");
        exit(1);
    }

    s = pthread_join(t1, NULL);
    if(s != 0){
        perror("pthread_join");
        exit(1);
    }
    s = pthread_join(t2, NULL);
    if(s != 0){
        perror("pthread_join");
        exit(1);
    }
    printf("glob = %d\n", glob);

    return 0;
}

static void *threadFunc(void *arg){
    int loops = *((int *) arg);
    int loc, j;

    for(j = 0; j < loops; j++){
        loc = glob;
        loc++;
        glob = loc;
    }
    return NULL;
}
