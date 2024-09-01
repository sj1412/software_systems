/*
============================================================================
Name : 9.c
Author : Soumya Jain
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change

Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

void file_info(const char *fname) {
    struct stat fstat;


    if (stat(fname, &fstat) < 0) {
        perror("stat");
        exit(EXIT_FAILURE);
    }


    printf("File: %s\n", fname);
    printf("  Inode: %ld\n", (long)fstat.st_ino);
    printf("  Number of hard links: %ld\n", (long)fstat.st_nlink);
    printf("  UID: %u\n", fstat.st_uid);
    printf("  GID: %u\n", fstat.st_gid);
    printf("  Size: %ld bytes\n", (long)fstat.st_size);
    printf("  Block size: %ld bytes\n", (long)fstat.st_blksize);
    printf("  Number of blocks: %ld\n", (long)fstat.st_blocks);

    printf("  Time of last access: %s", ctime(&fstat.st_atime));


    printf("  Time of last modification: %s", ctime(&fstat.st_mtime));

    printf("  Time of last change: %s", ctime(&fstat.st_ctime));
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
    printf("arguments less than 2, error!");
        exit(EXIT_FAILURE);
    }

    file_info(argv[1]);

    return 0;
}

/*output: opened file Q3_file.txt, here is the information about the same:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out Q3_file.txt
File: Q3_file.txt
  Inode: 2773874
  Number of hard links: 1
  UID: 1000
  GID: 1000
  Size: 0 bytes
  Block size: 4096 bytes
  Number of blocks: 0
  Time of last access: Wed Aug 28 22:46:39 2024
  Time of last modification: Wed Aug 28 22:17:16 2024
  Time of last change: Wed Aug 28 22:17:16 2024
*/
