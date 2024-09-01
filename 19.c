/*
============================================================================
Name : 19.c
Author : Soumya Jain
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>

unsigned long long rdtsc(){
 unsigned long long dst;
 __asm__ __volatile__ ("rdtsc":"=A" (dst));
}
int main(void){
int i,nano;
unsigned long long int start,end;
start=rdtsc();
for(i=0; i<=5000;i++)
getpid();
end=rdtsc();
nano=(end-start)/2.09;
printf("the function takes %d nanosec\n",nano);
}

/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc 19.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
the function takes 11482818 nanosec
*/
