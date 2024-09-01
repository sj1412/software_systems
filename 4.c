/*
============================================================================
Name : 4.c
Author : Soumya Jain
Description :Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
    const char *fname = "Q3_file.txt";
    int fd;

    fd = open(fname, O_RDWR);
    if (fd < 0) {
        perror("Error while opening file in read-write mode");
        return 1;
    }
   else{
printf("file opened in read-write mode"); 
}

    fd = open(fname, O_RDWR | O_CREAT | O_EXCL, 0666);
    if (fd < 0) {
        return 1;
    }

    printf("File created and opened  with O_EXCL system call.\n");
    close(fd);

    return 0;
}

/*output:
Q4
cc q4.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
file opened in read-write mode
from ls -l command we can see that file is created in rw mode.
-rw-rw-rw- 1 soumya soumya   691 Aug 26 22:58 q4.c
*/
