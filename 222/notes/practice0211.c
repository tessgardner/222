#include <stdio.h>

int main (int argc, char *argv[]) {
    FILE *fptr = fopen(argv[1], "rb");

    if (fptr == NULL) {
        printf("ERROR\n");
        return 1;
    }
    
    printf("Successful!\n");
    int ch1;
    for (int i = 0; i < 100; i++) {
        ch1 = fgetc(fptr);
        printf("%c", ch1);

    }
    fclose(fptr);
    printf("/n");

    return 0;
}