/*
============================================================================
Name : 18.c
Author : Soumya Jain
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>



void recLock(int fd, int record_num, int lock_type){

	struct flock lock;
	lock.l_type = lock_type;
	lock.l_whence = SEEK_SET;
	lock.l_start = record_num * 32;
	lock.l_len = 32;
	lock.l_pid = getpid();

	fcntl(fd, F_SETLKW, &lock);

	printf("Record %d locked...\n",record_num+1);

}

void unlock(int fd, int record_num){
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = record_num * 32;
    lock.l_len = 32;
    lock.l_pid = getpid();

    fcntl(fd, F_SETLK, &lock);

    printf("Record %d unlocked.\n", record_num+1);

}

void writeRec(int fd, int record_num, const char *data) {
    recLock(fd, record_num, F_WRLCK);   
    lseek(fd, record_num*32, SEEK_SET);
    printf("Writing in Record %d \n", record_num+1);
    write(fd, data, strlen(data));
    printf("Record %d updated\n", record_num+1);
    unlock(fd, record_num);
}

void readRec(int fd, int record_num) {
    char buffer[32];
    recLock(fd, record_num, F_RDLCK);    
    lseek(fd, record_num*32, SEEK_SET);
    printf("Reading Record %d \n", record_num+1);
    read(fd, buffer, 32);
    buffer[32 - 1] = '\0'; 
    printf("%s\n", buffer);
    unlock(fd, record_num);       
}


int main(){

	int fd = open("file_1.txt", O_RDWR | O_CREAT, 0666);

	writeRec(fd, 0, "Record 1: Data1\n");
    	writeRec(fd, 1, "Record 2: Data2\n");
    	writeRec(fd, 2, "Record 3: Data3\n");


	
    	readRec(fd, 1);


    	writeRec(fd, 0, "Record 1: Updated data\n");


    	readRec(fd, 0);

    	close(fd);
    	return 0;

}

/* output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc 18.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
Record 1 locked...
Writing in Record 1 
Record 1 updated
Record 1 unlocked.
Record 2 locked...
Writing in Record 2 
Record 2 updated
Record 2 unlocked.
Record 3 locked...
Writing in Record 3 
Record 3 updated
Record 3 unlocked.
Record 2 locked...
Reading Record 2 
Record 2: Data2

Record 2 unlocked.
Record 1 locked...
Writing in Record 1 
Record 1 updated
Record 1 unlocked.
Record 1 locked...
Reading Record 1 
Record 1: Updated data
*/
