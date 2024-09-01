/*
============================================================================
Name : 24.c
Author : Soumya Jain
Description : Write a program to create an orphan process.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

   
    pid = fork();

    if (pid < 0) {
     
        perror("cant create process");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        
       
        sleep(10);
        printf("Child process now has new Parent PID = %d\n", getppid());
        exit(EXIT_SUCCESS);
    } else {

        printf("Parent process: PID = %d\n", getpid());

    }
/* output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc q24.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
Parent process: PID = 77080
Child process: PID = 77081, Parent PID = 77080
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$
Child process now has new Parent PID = 1759
*/
