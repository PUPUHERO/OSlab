#define _GNU_SOURCE
#include <linux/unistd.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <string.h>
#define __NR_mysyscall 436

int main(){
    syscall(__NR_mysyscall);
    printf("Did I just finish?\nFind out in dmesg!\n");
    return 0;
}