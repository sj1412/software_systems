/*
============================================================================
Name : 30.c
Author : Soumya Jain
Description : Write a program to run a script at a specific time using a Daemon process
Date: 28th Aug, 2024.
============================================================================
*/
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
if(!fork()){
setsid();
chdir("/");
umask(0);
while(1){
sleep(4);
printf("child pid : %d\n",getpid());
printf("daemon process running\n");
}
}
else
exit(0);
}

/* output: shell independent execution of process.
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc q30.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ child pid : 6264
daemon process running
child pid : 6264
daemon process running
child pid : 6264
*/
