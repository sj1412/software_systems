/*
============================================================================
Name : 7.c
Author : Soumya Jain
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>

int  BUFFER_SIZE=1024;

void copy_file(const char *source, const char *destination) {
    FILE *source_file = fopen(source, "rb");
    if (source_file == NULL) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    FILE *destination_file = fopen(destination, "wb");
    if (destination_file == NULL) {
        fclose(source_file);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
        size_t bytes_written = fwrite(buffer, 1, bytes_read, destination_file);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            fclose(source_file);
            fclose(destination_file);
            exit(EXIT_FAILURE);
        }
    }


    fclose(source_file);
    fclose(destination_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {

        return EXIT_FAILURE;
    }

    copy_file(argv[1], argv[2]);

    printf("File copied from %s to %s successfully.\n", argv[1], argv[2]);

    return EXIT_SUCCESS;
}

/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cc q7.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ touch file47.txt(file created to copy data from file_1.txt)
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out file_1.txt file47.txt
File copied from file_1.txt to file47.txt successfully.(printed message on successful execution)
*/
