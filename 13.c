/*
============================================================================
Name : 13.c
Author : Soumya Jain
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <errno.h>
#include <string.h>

int main() {
    
    struct timeval time;
    time.tv_sec = 10;
    time.tv_usec = 0;

    
    fd_set readfd;
    FD_ZERO(&readfd);
    FD_SET(STDIN_FILENO, &readfd);

    
    int result = select(STDIN_FILENO + 1, &readfd, NULL, NULL, &time);

    if (result < 0) {
        
        perror("select");
        return 1;
    } else if (result == 0) {
        
        printf("No data available within 10 seconds.\n");
    } else {
          if (FD_ISSET(STDIN_FILENO, &readfd)) {
            printf("Data is available on STDIN.\n");
        }
    }

    return 0;
}
/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
No data available within 10 seconds.
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc 13.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
abc
Data is available on STDIN.
*/
