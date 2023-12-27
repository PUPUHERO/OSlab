#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 16

int allocate_frame(int FreeFrameList[]){
    int i;
    do
    {
        i = rand() % 16;
    } while (FreeFrameList[i] == 1);
    FreeFrameList[i] = 1;
    return i;
}

int free_frame(int FreeFrameList[], int frame){
    FreeFrameList[frame] = 0;
    return 0;
}

void putInFrame(char *physicalMemory, int frame, char data1, char data2){
    physicalMemory[2*frame] = data1;
    physicalMemory[2*frame+1] = data2;
}

void get_a_process(char p_name, char *physicalMemory, int FreeFrameList[], char data[6]){
    int FrameList[3] = {0};
    printf("process %c's logical memory:\n", p_name);
    printf("page\tdata\n");
    for(int i = 0; i < 3; i++){
        int frame = allocate_frame(FreeFrameList);
        FrameList[i] = frame;
        putInFrame(physicalMemory, frame, data[2*i], data[2*i+1]);
        printf("%d\t%c%c\n", i, data[2*i], data[2*i+1]);
    }
    printf("process %c's page table:\n", p_name);
    for(int i = 0; i < 3; i++){
        printf("%d\t%d\n", i, FrameList[i]);
    }
}

void printFrameList(char *physicalMemory){
    int i;
    printf("physical memory: \n");
    printf("frame\toffset\tdata\n");
    for(i = 0; i < MAX; i++){
        for(int j = 0; j < 2; j++){
            printf("%d\t%d\t%c\n", i, j ,physicalMemory[2*i+j]);
        }
    }
    printf("\n");
}

void printfFreeFrameList(int *FreeFrameList){
    printf("FreeFrameList: \n");
    for(int i = 0; i < MAX; i++){
        if (FreeFrameList[i] == 0)
        {
            printf("%d ", i);
        }        
    }
    printf("\n");
}

int main(void){
    srand(time(NULL));
    int FreeFrameList[MAX] = {0};
    char physicalMemory[MAX * 2] = {" "};
    get_a_process('A', physicalMemory, FreeFrameList, "ABCDBA");
    get_a_process('B', physicalMemory, FreeFrameList, "XYZLKK");
    printFrameList(physicalMemory);
    printfFreeFrameList(FreeFrameList);
}
