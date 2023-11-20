#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void child(void *arg){
    int *input = (int *)arg;
    int *result = (int *)malloc(sizeof(int));
    result[0] = input[0] + input[1];
    pthread_exit((void *)result);
}

int main(){
    pthread_t tid;
    void *ret;
    int input[2] = {1, 2};
    pthread_create(&tid, NULL, (void *)child, (void *)input);
    pthread_join(tid, &ret);
    int result = *(int *)ret;
    printf("%d + %d = %d\n", input[0], input[1], result);
    return 0;
}