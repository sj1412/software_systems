/*
============================================================================
Name : 5.c
Author : Soumya Jain
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd
Date: 28th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int  FILES=5;
#define FILENAME "/home/soumya/repo1/file_%d.txt"

int main() {
    int i;
    int fdescriptor[FILES];
    char filename[50];

    while (1) {
        for (i = 0; i < FILES; i++) {

            snprintf(filename, sizeof(filename), FILENAME, i);


            fdescriptor[i] = open(filename, O_CREAT | O_RDWR, 0644);
            if (fdescriptor[i] < 0) {
                perror("open");
                exit(EXIT_FAILURE);
            }
        }

        for (i = 0; i < FILES; i++) {
            close(fdescriptor[i]);
        }
    }

    return 0;
}

/*output: from ls -l command we can check that 5 files are created.
-rw-r--r-- 1 soumya soumya     0 Aug 29 15:05 file_0.txt
-rw-r--r-- 1 soumya soumya     0 Aug 29 15:05 file_1.txt
-rw-r--r-- 1 soumya soumya     0 Aug 29 15:05 file_2.txt
-rw-r--r-- 1 soumya soumya     0 Aug 29 15:05 file_3.txt
-rw-r--r-- 1 soumya soumya     0 Aug 29 15:05 file_4.txt
*/
