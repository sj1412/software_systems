/*
============================================================================
Name : 21.c
Author : Soumya Jain
Description : Write a program, call fork and print the parent and child process id.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    
    pid_t pid = fork();

    
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }


    if (pid == 0) {
        
        printf("Child Process:\n");
        printf("  PID: %d\n", getpid());
        printf("  Parent PID: %d\n", getppid());
    } else {

        printf("Parent Process:\n");
        printf("  PID: %d\n", getpid());
        printf("  Child PID: %d\n", pid);
    }

    return EXIT_SUCCESS;
}

/* output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc 21.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
Parent Process:
  PID: 10069
  Child PID: 10070
Child Process:
  PID: 10070
  Parent PID: 10069
*/
