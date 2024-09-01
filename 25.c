/*
============================================================================
Name : 25.c
Author : Soumya Jain
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
int i,j,k;
if(!(i=fork()))
sleep(1);
else
if(!(j=fork()))
sleep(20);
else
if(!(k=fork()))
sleep(30);
else{
waitpid(j,NULL,0);
printf("waiting");}
}

/* output: the parent is waiting for child process with pid=j and thus program prints message "waiting".
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc q25.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
waiting
*/
