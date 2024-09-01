/*
============================================================================
Name : 11c.c
Author : Soumya Jain
Description :Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
c. use fcntl
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main() {
    const char *filename="file_4.txt";
    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    
    int fdup = fcntl(fd, F_DUPFD, 5);
    if (fdup < 0) {
        perror("fcntl F_DUPFD");
        close(fd);
        return 1;
    }

    
    const char *data1 = "Data from original descriptor.\n";
    const char *data2 = "Data from duplicated descriptor.\n";

    ssize_t bytes_written = write(fd, data1, strlen(data1));
    if (bytes_written < 0) {
        perror("write");
        close(fd);
        close(fdup);
        return 1;
    }

    
    bytes_written = write(fdup, data2, strlen(data2));
    if (bytes_written < 0) {
        perror("write");
        close(fd);
        close(fdup);
        return 1;
    }

    
    close(fd);
    close(fdup);
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    char buffer[1024];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        perror("read");
        close(fd);
        return 1;
    }


    printf("File content after operations:\n%s\n", buffer);
    close(fd);

    return 0;
}
/*output: file_4.txt is written by original and duplicate descriptor.(file_4.txt is passed as parameter for *file in code) 
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc 11c.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
File content after operations:
Data from original descriptor.
Data from duplicated descriptor.*/
