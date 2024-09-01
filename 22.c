/*
============================================================================
Name : 22.c
Author : Soumya Jain
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    const char *file;
    int fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        
        const char *child_msg = "Child process writing.\n";
        write(fd, child_msg, sizeof(child_msg) - 1);
        close(fd);
        printf("child process done\n");
        exit(EXIT_SUCCESS);
    } else {

        const char *parentmsg = "writing using parent process.\n";
        write(fd, parentmsg, sizeof(parentmsg) - 1);

        wait(NULL);

        close(fd);
        printf("Parent process done.\n");
    }

    return 0;
}
/* output:written in file q22file.txt using both parent process and child process.
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out q22file.txt
child process done
Parent process done.
*/
