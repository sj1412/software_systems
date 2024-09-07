/*
============================================================================
Name : 29.c
Author : Soumya Jain
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <errno.h>
#include <string.h>

void print_policy(int policy) {
    switch (policy) {
        case SCHED_FIFO:
            printf("Current scheduling policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current scheduling policy: SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("Current scheduling policy: SCHED_OTHER\n");
            break;
        default:
            printf("Current scheduling policy: Unknown\n");
            break;
    }
}

int main() {
    int policy;
    struct sched_param param;

    policy = sched_getscheduler(0);

    if (policy == -1) {
        perror("sched_getscheduler");
        return EXIT_FAILURE;
    }


    print_policy(policy);


    int new_policy = SCHED_RR;
    param.sched_priority = 10;

    
    if (sched_setscheduler(0, new_policy, &param) == -1) {
        perror("sched_setscheduler");
        return EXIT_FAILURE;
    }

    
    policy = sched_getscheduler(0);
    if (policy == -1) {
        perror("sched_getscheduler");
        return EXIT_FAILURE;
    }

    print_policy(policy);

    return EXIT_SUCCESS;
}
/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc q29.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
Current scheduling policy: SCHED_OTHER
sched_setscheduler: Operation not permitted
*/

