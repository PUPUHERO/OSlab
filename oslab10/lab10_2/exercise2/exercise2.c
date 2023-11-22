#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void child(void *arg){
    int *input = (int *)arg;
    input[2] = input[0] + input[1];
    
    while(1)
    {
        sleep(1);
        pthread_testcancel();
    }

    pthread_exit((void *)&input[2]);
}

int main(){
    pthread_t tid;
    void *ret;
    int input[3] = {1, 2, 0};
    pthread_create(&tid, NULL, (void *)child, (void *)input);

    for (int i = 1; i < 4; i++)
    {
        sleep(1);
        printf("sleep: %d\n", i);
    }
    pthread_cancel(tid);
    printf("pthread_cancel\n");
    
    // pthread_join(tid, &ret);
    // input[2] = *(int *)ret;
    printf("%d + %d = %d\n", input[0], input[1], input[2]);
    return 0;
}
