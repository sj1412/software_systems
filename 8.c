/*
============================================================================
Name : 8a.c
Author : Soumya Jain
Description :Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
int MAX_LEN= 1024;
int main() {
    FILE *file;
    char line[MAX_LEN];

    const char *file_path="/home/soumya/repo1/file_0.txt";


    file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }


    while (fgets(line, sizeof(line), file)) {

        printf("%s", line);
    }

    fclose(file);

    return 0;
}

/* output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out
1234567890abcdefghij soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ 
*/

