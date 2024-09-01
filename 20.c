/*
============================================================================
Name : 20.c
Author : Soumya Jain
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    
    int current_priority = getpriority(PRIO_PROCESS, getpid());
    if (current_priority == -1) {
        perror("getpriority");
        return EXIT_FAILURE;
    }

    printf("Current nice value: %d\n", current_priority);

    
    int new_priority = current_priority + 5;
    if (setpriority(PRIO_PROCESS, getpid(), new_priority) == -1) {
        perror("setpriority");
        return EXIT_FAILURE;
    }



    printf("Updated nice value: %d\n", new_priority);

    return EXIT_SUCCESS;
}

/*output: changed priority of process using nice system call.
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
Current nice value: 0
Updated nice value: 5
*/
