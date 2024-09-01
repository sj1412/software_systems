/*
============================================================================
Name : 1a.c
Author : Soumya Jain
Description : Create the following types of a files using system call
a. soft link (symlink system call)
Date:30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {

	if (symlink("/home/soumya/repo1/file_1.txt","/home/soumya/repo1/lnknew1.txt") == -1){
		perror("cant create softlink");
		return 1;
	}

else{
printf("softlink created");
	return 0;
}
}
/*Q1a-output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ nano 1a.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc 1a.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
softlink created
after ls command:
1a.c                           q24.c
 26                             q25.c
 26.c                           q27a.c
 a.out                          q27b.c
 executablefor26.c              q27c.c
 f8.txt                         q27d.c
 file_0.txt                     q27e.c
 file_1.txt                     q28.c
 file_2.txt                     q29.c
 file_3.txt                     q2.c
 file47.txt                     q30.c
 file_4.txt                     q3.c
''$'\350\030''g}'$'\206\177'    Q3_file.txt
 lnknew1.txt(softlink created here)
*/
