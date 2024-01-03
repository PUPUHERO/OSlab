#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int count = 0;

void *thread_function(void *arg) {
    // code to be executed by the thread
    for (int i = 0; i < 250000; i++) {
        count++;
    }
    printf("Thread ID is: %ld complete, count is: %d\n", pthread_self(), count);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[4];
    int i;

    for (i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, thread_function, NULL);
    }

    // wait for all threads to finish
    for (i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final count: %d\n", count);

    return 0;
}
