/*
============================================================================
Name : 16a.c
Author : Soumya Jain
Description : Write a program to perform mandatory locking.
a. Implement write lock
Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    

    int f = open(argv[1], O_RDWR);
    struct flock lock;

    lock.l_type = F_WRLCK; 
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    fcntl(f, F_SETLKW, &lock);

    printf("Write lock set.\n");

    printf("File locked for writing. Press Enter to release lock...\n");
    getchar();

    lock.l_type=F_UNLCK;
    fcntl(f, F_SETLK, &lock);
    printf("File unlocked.");

    close(f);
    return 0;
}
/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ nano 16a.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc 16a.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out file_0.txt
Write lock set.
File locked for writing. Press Enter to release lock...

File unlocked.
*/
