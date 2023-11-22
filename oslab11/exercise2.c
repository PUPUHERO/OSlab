#include<signal.h>
#include<stdio.h>
#include<unistd.h>

int counter = 0;

void first_handler(int signum){
    printf("How are you!!!!\n");
}

void second_handler(int signum){
    printf("I'm fine!!!!\n");
}

void alarm_handler(int signum){
    // alarm(3);
    if(counter == 0){
        signal(SIGINT, second_handler);
    }else if (counter == 1){
        signal(SIGINT, SIG_DFL);
    }
    counter++;
}

int main(){
    signal(SIGINT, first_handler);
    signal(SIGALRM, alarm_handler);
    
    alarm(3);
    for (; ;)
    {
        pause();
    }    
    return 0;
}