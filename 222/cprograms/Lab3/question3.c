#include <stdio.h>
#include <string.h> 

int main() {

    // initializing variables
    int intInput = 0; // value determined by input
	char binOutput[33] = ""; // supports up to 32 bits
    int current_val; // current value being compared to counter
    int counter; // iterator for each digit when calculating binary number
    int i; // index of binary string

    printf("Enter a negative value at any point to quit.\n");

    while (intInput >= 0) {
        // geting input....
        printf("Enter a number of seconds to convert: ");
        scanf("%d", &intInput);

        // setting up variables to work with current input
        current_val = intInput;
        counter = 1;
        i = 0;

        // working upwards to find highest digit
        while (counter <= current_val && counter > 0) {
            counter = counter * 2;
        }
        counter = counter / 2; // backtracking once value has been found

        // moving back downwards, filling the string with either 1s or 0s
        while (counter > 0) {
            if (counter > current_val) {
                binOutput[i++] = '0';
                
            }
            else if (counter <= current_val) {
                binOutput[i++] = '1';
                current_val = current_val - counter;
            }
        counter = counter / 2; // iterator of while loop
    }

    binOutput[i] = '\0'; // null terminating string
    printf("Binary equivalent: %s\n", binOutput); // printing the output!
    }

    // value less thatn 0 has been found
    printf("Bye. \n");
    return 0;
}