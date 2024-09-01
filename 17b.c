/*
============================================================================
Name : 17b.c
Author : Soumya Jain
Description:In reference to previous question 17a write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

	int fd;

	fd=open("newticket.txt", O_RDONLY);
	if (fd==-1){
		perror("Error in opening the file");
	  return 1;
	 }

	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;

	fcntl(fd, F_SETLK, &lock);

	char buffer[32];

	read(fd, buffer, sizeof(buffer));

	int ticket_number = atoi(buffer);

	printf("Current ticket number: %d\n", ticket_number);

	ticket_number++;

	snprintf(buffer, sizeof(buffer), "%d\n", ticket_number);

	write(fd, buffer, strlen(buffer));

	printf("New Ticket Number: %d\n", ticket_number);

	
	lock.l_type = F_UNLCK;

	fcntl(fd, F_SETLK, &lock);


	close(fd);


	return 0;
}

/*output:ticket number incremented on adding a new ticket.
Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
*/
