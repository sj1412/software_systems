/*
============================================================================
Name : 23.c
Author : Soumya Jain
Description : Write a program to create a Zombie state of the running program.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

void create_zombie_process() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {

        printf("Child process (PID %d) exiting...\n", getpid());
        exit(EXIT_SUCCESS);
    } else {

        printf("Parent process (PID %d) sleeping...\n", getpid());
        sleep(60);
        printf("Parent process waking up. Zombie child should still be present.\n");
        int status;
        waitpid(pid, &status, WNOHANG);
        printf("Parent process (PID %d) cleaned up the zombie.\n", getpid());
    }
}

int main() {
    create_zombie_process();
    return EXIT_SUCCESS;
}

/* output: printed message on sucessful execution of program.
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc q23.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
Parent process (PID 5832) sleeping...
Child process (PID 5833) exiting...
*/
