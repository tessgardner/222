#include <stdio.h>

int main() {
    int intInput = 0; 

        printf("Enter a negative value at any point to quit.\n");

      

        //while (intInput >= 0) {
            printf("Enter an integer: ");
            scanf("%d", &intInput);
            // work will go here
            for (int i = 2; i <= 100; i*i) {
                printf("%d ", i);
            }
            
        //}

        printf("Bye.");

    return 0;
}