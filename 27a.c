/*
============================================================================
Name : 27a.c
Author : Soumya Jain
Description : Write a program to execute ls -Rl by the following system calls
a. execl
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        
        execl("/bin/ls", "ls", "-Rl", (char *)NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    } else {
        
        if (wait(NULL) == -1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }
        
        printf("Child process has completed execution.\n");
    }

    return 0;
}

/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc q27a.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
.:
total 152
-rw-rw-r-- 1 soumya soumya    64 Aug 29 23:18 ''$'\350\b\316\036''*'$'\177'
-rw-rw-r-- 1 soumya soumya  1304 Aug 29 23:28  11b.c
-rw-rw-r-- 1 soumya soumya  1342 Aug 29 23:37  11c.c
-rw-rw-r-- 1 soumya soumya   303 Aug 30 11:14  15.c
-rwxrwxr-x 1 soumya soumya 16160 Aug 30 18:58  a.out
-rw-rw-r-- 1 soumya soumya   104 Aug 29 14:50  f8.txt
-rwxrwxrwx 1 soumya soumya    20 Aug 29 22:40  file_0.txt
-rw-r--r-- 1 soumya soumya     0 Aug 29 15:05  file_1.txt
-rw-r--r-- 1 soumya soumya     0 Aug 29 15:05  file_2.txt
-rw-r--r-- 1 soumya soumya     0 Aug 29 15:05  file_3.txt
-rw-r--r-- 1 soumya soumya    64 Aug 29 23:38  file_4.txt
-rw-rw-r-- 1 soumya soumya    64 Aug 29 23:28 ''$'\350\030''g}'$'\206\177'
-rw-rw-r-- 1 soumya soumya     0 Aug 29 23:47  NEWfile.txt
-rw-rw-r-- 1 soumya soumya     0 Aug 30 15:50  nwefile2.txt
-rw-rw-r-- 1 soumya soumya  1476 Aug 29 22:40  q10.c
-rw-rw-r-- 1 soumya soumya  1330 Aug 29 23:18  q11a.c
-rw-rw-r-- 1 soumya soumya  1189 Aug 29 23:47  q12.c
-rw-rw-r-- 1 soumya soumya   690 Aug 30 00:49  q13.c
-rw-rw-r-- 1 soumya soumya  1332 Aug 30 11:02  q14.c
-rw-rw-r-- 1 soumya soumya  1878 Aug 30 13:37  q16.c
-rw-rw-r-- 1 soumya soumya   353 Aug 30 13:51  Q19.c
-rw-rw-r-- 1 soumya soumya   596 Aug 30 16:06  q20.c
-rw-rw-r-- 1 soumya soumya   510 Aug 30 16:11  q21.c
-rw-rw-r-- 1 soumya soumya   869 Aug 30 18:45  q22.c
-rw-rw-r-- 1 soumya soumya     0 Aug 30 18:44  q22file.txt
-rw-rw-r-- 1 soumya soumya   225 Aug 30 14:07  q25.c
-rw-rw-r-- 1 soumya soumya   558 Aug 30 18:58  q27a.c
-rw-rw-r-- 1 soumya soumya   881 Aug 30 18:53  q28.c
-rwxrwxrwx 1 soumya soumya   273 Aug 28 22:27  q2.c
-rwxrwxrwx 1 soumya soumya   431 Aug 28 22:26  q3.c
-rw-r--r-- 1 soumya soumya     0 Aug 28 22:17  Q3_file.txt
-rwxrwxr-x 1 soumya soumya 16072 Aug 28 22:43  q4
-rw-rw-rw- 1 soumya soumya   691 Aug 28 22:58  q4.c
-rw-rw-r-- 1 soumya soumya   749 Aug 29 15:08  q5.c
-rw-rw-r-- 1 soumya soumya   474 Aug 28 23:33  q6.c
-rw-rw-r-- 1 soumya soumya   482 Aug 28 23:27  q7.c
-rw-rw-r-- 1 soumya soumya   360 Aug 29 14:54  q8.c
-rw-rw-r-- 1 soumya soumya  1078 Aug 28 23:48  q9.c
-rw-rw-r-- 1 soumya soumya     0 Aug 21 21:43  README.md
-rw-r--r-- 1 soumya soumya    14 Aug 30 18:45 ''$'\363\017\036\372''Uf'$'\017\357\300''H'$'\211\345''AWAVAUL'$'\215''-3'$'\273'
Child process has completed execution.
*/
