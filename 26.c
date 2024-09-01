/*
============================================================================
Name : 26.c
Author : Soumya Jain
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    char *cmd = "./a.out";
    char *args[] = { "a.out", "Soumya", NULL };
    execvp(cmd, args);
    perror("execvp");
    return 1;
}

/* output: the executablefor26.c file has code to print "Hello, arg[1]".
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ nano executablefor26.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc -o a.out executablefor26.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ nano 26.c 
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc -o 26 26.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./26
Hello, Soumya
*/
