#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

static __thread int glob = 0;
int arg1 = 50;
int arg2 = 100;

void *incr(void *loops){
    int loc, j;
    for(j = 0; j < *(int *)loops; j++){
        loc = glob;
        loc++;
        glob = loc;
    }
    printf("Thread ID %ld, glob = %d\n", pthread_self(), glob);
}

int main()
{
    pthread_t id[2];
    pthread_create(&id[0], NULL, incr, &arg1);
    pthread_create(&id[1], NULL, incr, &arg2);

    printf("(main thread) golb value before run 2 threads: %d\n", glob);
    pthread_join(id[0], NULL);
    pthread_join(id[1], NULL);
    printf("(main thread) golb value after run 2 threads: %d\n", glob);

    return 0;
}
