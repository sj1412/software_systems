/*
============================================================================
Name : 14.c
Author : Soumya Jain
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const char* file_type(const char* file_name) {
    const char* extension = strrchr(file_name, '.');
       if (extension == NULL) {
        return "Unknown File Type";
    }

    if (strcmp(extension, ".txt") == 0) return "Text File";
    if (strcmp(extension, ".c") == 0) return "C Source File";
    if (strcmp(extension, ".h") == 0) return "Header File";
    if (strcmp(extension, ".jpg") == 0) return "JPEG Image";
    if (strcmp(extension, ".png") == 0) return "PNG Image";
    if (strcmp(extension, ".pdf") == 0) return "PDF Document";
    if (strcmp(extension, ".docx") == 0) return "Word Document";
    if (strcmp(extension, ".xlsx") == 0) return "Excel Spreadsheet";
    if (strcmp(extension, ".html") == 0) return "HTML Document";
    if (strcmp(extension, ".csv") == 0) return "CSV File";

    return "Unknown File Type";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {

        return EXIT_FAILURE;
    }

    const char* file_path = argv[1];

    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Error");
        return EXIT_FAILURE;
    }
    
    fclose(file);

    
    const char* newfile_type = file_type(file_path);
    printf("The file '%s' is of type: %s\n", file_path, newfile_type);

    return EXIT_SUCCESS;
}
/*output: function prints the type of file opened, by checking the file extension.
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out file_0.txt
The file 'file_0.txt' is of type: Text File
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ ./a.out 11c.c
The file '11c.c' is of type: C Source File
*/
