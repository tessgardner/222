#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main () {
    int counter = 0;
    while (1) { // this runs FOREVER
        fork();
        printf("%d\n", counter);
        counter++;
    }
}