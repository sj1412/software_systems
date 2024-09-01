/*
============================================================================
Name : 12.c
Author : Soumya Jain
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void print_flags(int flags) {
    printf("File Status Flags:\n");
    if (flags & O_RDONLY) printf("Read-only\n");
    if (flags & O_WRONLY) printf("Write-only\n");
    if (flags & O_RDWR)   printf("Read and Write\n");
    if (flags & O_APPEND) printf("Append mode\n");
    if (flags & O_CREAT)  printf("Create file if it doesn't exist\n");
    if (flags & O_TRUNC)  printf("Truncate file to zero length\n");
    if (flags & O_EXCL)   printf("Exclusive creation\n");
    if (flags & O_NONBLOCK) printf("Non-blocking mode\n");
    if (flags & O_SYNC)   printf("Synchronize file updates)\n");
}

int main() {

    const char *filename = "NEWfile.txt";

    int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("open");
        return 1;
    }


    int flags = fcntl(fd, F_GETFL);
    if (flags < 0) {
        perror("fcntl F_GETFL");
        close(fd);
        return 1;
    }


    print_flags(flags);
    if (close(fd) < 0) {
        perror("close");
        return 1;
    }

    return 0;
}
/*output: function prints the  file status.
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc 12.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
File Status Flags:
Read and Write
*/
