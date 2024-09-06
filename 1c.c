/*
============================================================================
Name : 1c.c
Author : Soumya Jain
Description :Create the following types of a files using system call: FIFO
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main() {
    const char *fifo_path = "/home/soumya/repo1/newfifo";
    if (mkfifo(fifo_path, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    printf("FIFO %s created successfully.\n", fifo_path);

    return 0;
}
/*output:Code prints FIFO (file path) created succesfully if file is created by mkfifo system call.
Q1c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc 1c.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
FIFO /home/soumya/repo1/newfifo created successfully.*/
