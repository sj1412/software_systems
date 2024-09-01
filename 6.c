/*
============================================================================
Name : 6.c
Author : Soumya Jain
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;


    while ((bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0) {
               if (write(STDOUT_FILENO, buffer, bytes_read) != bytes_read) {
            perror("Error writing");
            return 1;
        }
    }
    if (bytes_read < 0) {
        perror("Error reading from STDIN");
        return 1;
    }

    return 0;
}
/* output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
I/P:"i am giving input at std input to get o/p on std output."
O/P:"i am giving input at std input to get o/p on std output."
*/
