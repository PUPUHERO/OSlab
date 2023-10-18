#include<fcntl.h>
#include<stdio.h>
#include<sys/mman.h>

#define SHM_NAME "/mySharedMemory"
#define SHM_SIZE 1024

int main(){
    int fd = shm_open(SHM_NAME, O_RDONLY, 0666);
    if (fd == -1){
        perror("Failed to open shared memory");
        return 1;
    }

    void *map_addr = mmap(NULL, SHM_SIZE, PROT_READ, MAP_SHARED, fd, 0);
    if (map_addr == MAP_FAILED){
        perror("Failed to map shared memory");
        return 1;
    }
    // printf("%p\n", (char*)map_addr);
    printf("Received: %s", (char*)map_addr);

    return 0;
}

