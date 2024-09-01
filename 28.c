/*
============================================================================
Name : 28.c
Author : Soumya Jain
Description : Write a program to get maximum and minimum real time priority.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <errno.h>

int main() {
    
    int maxpriority_fifo = sched_get_priority_max(SCHED_FIFO);
    int minpriority_fifo = sched_get_priority_min(SCHED_FIFO);

    
    int maxpriority_rr = sched_get_priority_max(SCHED_RR);
    int minpriority_rr = sched_get_priority_min(SCHED_RR);

    
    if (maxpriority_fifo == -1 || minpriority_fifo == -1 || 
        maxpriority_rr == -1 || minpriority_rr == -1) {
        perror("sched_get_priority_max/min");
        exit(EXIT_FAILURE);
    }

    
    
    printf("Real time Maximum priority fifo: %d\n", maxpriority_fifo);
    printf("Real time Minimum priority fifo: %d\n", minpriority_fifo);


    printf("Real time Maximum priority for round robin: %d\n", maxpriority_rr);
    printf("Real time Minimum priority for round robin: %d\n", minpriority_rr);

    return 0;
}

/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc q28.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
Real time Maximum priority fifo: 99
Real time Minimum priority fifo: 1
Real time Maximum priority for round robin: 99
Real time Minimum priority for round robin: 1
*/
