/*
============================================================================
Name : 3.c
Author : Soumya Jain
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    const char *fname = "Q3_file.txt";


    int fd = creat(fname, 0644);


    if (fd == -1) {
        perror("creat");
        return 1;
    }

    printf("File descriptor value: %d\n", fd);


    return 0;
}

/* output:
File descriptor value: 3
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ nano q3.c
from ls command we can see a new file Q3_file.txt is created.
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ls
a.out  q2.c  q3.c  Q3_file.txt
*/
