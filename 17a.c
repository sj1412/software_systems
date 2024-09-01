/*
============================================================================
Name : 17a.c
Author : Soumya Jain
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit.
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){

	int fd, input;
	char buffer[32];

	fd = open("newticket.txt", O_WRONLY);

	if (fd==-1){
		printf("Error in opening file\n");
		return 1;
	}

	printf("Enter the ticket Number: ");
	scanf("%d",&input);

	snprintf(buffer, sizeof(buffer), "%d\n", input);

	write(fd, &buffer, strlen(buffer));

	close(fd);

	return 0;
}
/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ touch newticket.txt
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc 17a.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
Enter the ticket Number: 1
*/
