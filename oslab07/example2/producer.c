#include<fcntl.h>
#include<stdio.h>
#include<sys/mman.h>
#include<unistd.h>

#define SHM_NAME "/mySharedMemory"
#define SHM_SIZE 1024

int main(){
    int fd = shm_open(SHM_NAME, O_RDWR | O_CREAT, 0644);
    if (fd == -1){
        perror("Failed to open shared memory");
        return 1;
    }

    int truncate = ftruncate(fd, SHM_SIZE);
    if (truncate == -1){
        perror("Failed to truncate shared memory");
        return 1;
    }

    void *addr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED){
        perror("Failed to map shared memory");
        return 1;
    }

    char *ptr, buffer[SHM_SIZE];
    ptr = (char*)addr;

    printf("Send to receiver: \n");
    printf("> ");
    fgets(buffer, SHM_SIZE, stdin);

    sprintf(ptr, "%s", buffer);

    if (munmap(addr, SHM_SIZE) == -1){
        perror("Failed to unmap shared memory");
        return 1;
    }

    if(close(fd) == -1){
        perror("Failed to close shared memory");
        return 1;
    }

    return 0;
}