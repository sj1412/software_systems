/*
============================================================================
Name :1b.c
Author : Soumya Jain
Description : Create the following types of a files using (ii) system call
b. hard link (link system call)
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {

	if (link("/home/soumya/repo1/file_2.txt","/home/soumya/repo1/NewHardLink.txt") == -1){
		perror("syslink error");
		return 1;
	}
else{
printf("hardlink created");
	return 0;
}
}
/*output:
Q1.b
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ nano 1b.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc 1b.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
hardlink created*/
