/*
============================================================================
Name : 10.c
Author : Soumya Jain
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {

    const char *filename = "file_0.txt";


    int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("open");
        return 1;
    }


    const char *data = "1234567890";
    ssize_t write_bytes = write(fd, data, 10);
    if (write_bytes != 10) {
        perror("write");
        close(fd);
        return 1;
    }
    printf("10 bytes written.\n");

    
    off_t offset = 10;
    off_t newposition = lseek(fd, offset, SEEK_SET);
    if (newposition == (off_t)-1) {
        perror("lseek");
        close(fd);
        return 1;
    }
    if (newposition == offset) {
        printf("File pointer moved by %ld bytes.\n",(long)offset);
    } else {
        printf("Failed to move file pointer. lseek returned %ld.\n", (long)newposition);
        close(fd);
        return 1;
    }

    
    const char *data2 = "abcdefghij";
    write_bytes = write(fd, data2, 10);
    if (write_bytes != 10) {
        perror("write-error");
        close(fd);
        return 1;
    }
    printf("Written another 10 bytes to the file.\n");


    close(fd);


    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    char buffer[21];
    ssize_t bytes_read = read(fd, buffer, 20);
    if (bytes_read < 0) {
        perror("read-error");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}

/*output: file_0.txt was opened and written.
for part a: message printed on successful execution of program.
10 bytes written.
File pointer moved by 10 bytes.
Written another 10 bytes to the file.
--------------------------------------------
for part b:'0000'in output depicts space between bytes written.
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ od -x file_0.txt
0000000 3231 3433 3635 3837 3039 6261 6463 6665
0000020 6867 6a69
0000024
*/
