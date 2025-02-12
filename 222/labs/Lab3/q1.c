/*
* Name(s): Tess Gardner
* Date: 2/11/2025
* Program Description: Write a C program q1.c that essentially mimics the cp terminal com-
mand, this command copies a source file and pastes it to a destination file. If
the user fails to give arguments via the CLI show a usage message and gracefully
exit.
*/

// importing libraries
#include <stdio.h>
#include "checksum.h"

// used geeksforgeeks.org and tutorialspoint.com to learn how to use 
// fopen(), fgetc(), fputc(), and fclose()

// command line arguments included within main() so user can input their files
int main(int argc, char *argv[]) {

    // initializing variables:
    // files
    FILE *fptr1 = fopen(argv[1], "rb");
    FILE *fptr2 = fopen(argv[2], "wb");
    // both of these variabes are used to copy bits from one file to the next
    int ch;
    int count = 0;

    // ensuring 3 arguments are given
    if (argc != 3) {
        printf("Usage: ./copyfile <source_file> <destination_file>\n");
        return 1;
    }
  
    // ensuring the files can be opened
    if (fptr1 == NULL) {
        printf("Error opening source file: No such file or directory (%s)\n", argv[1]);
        return 1;
    }
    if (fptr2 == NULL) {
        printf("Error opening destination file: No such file or directory (%s)\n", argv[2]);
        return 1;
    }

    // copying bits from file1 to file2
    // When ch = EOF we've reached the end of the file
    while ((ch = fgetc(fptr1)) != EOF) {
        fputc(ch, fptr2);
        count++;        
    }

    // closing out of each file
    fclose(fptr1);
    fclose(fptr2);

    // output
    printf("File copied successfully.\n");
    printf("Checksum of %s is %s\n", argv[1], fileChecksum(argv[1]));
    printf("Checksum of %s is %s\n", argv[2], fileChecksum(argv[2]));

    return 0; // done :)
}