#include <stdio.h>

int main() {

    // defining constants
    const int HOURSINDAY = 24;
    const int MINSINHOUR = 60;
    const int SECSINMIN = 60;

    int days;
    int hours;
    int mins;
    int secs;

    int timevar = 0; // variable the user imputs
    int newtime; // variable that will be manipulated to get final result

    printf("Enter a negative value at any point to quit.\n");

    // while loop to ensure the user is continually prompted until a negative number is entered
    while (timevar >= 0) {

        days = 0;
        hours = 0;
        mins = 0;
        secs = 0;

        // prompting user and updating variables to reflect
        printf("Enter a number of seconds to convert: ");
        scanf("%d", &timevar);
        newtime = timevar;
       
        // the conversion process
        while (newtime >= 0) {
            if (newtime >= (HOURSINDAY * MINSINHOUR * SECSINMIN)) {
                newtime = newtime - (HOURSINDAY * MINSINHOUR * SECSINMIN);
                days++;
            }
            else if (newtime >= (MINSINHOUR * SECSINMIN)) {
                newtime = newtime - (MINSINHOUR * SECSINMIN);
                hours ++;
            }
            else if (newtime >= SECSINMIN) {
                newtime = newtime - SECSINMIN;
                mins++;

            }
            else if (newtime > 0) {
                newtime = newtime - 1;
                secs ++;
            }
            else {
                break;
            }
        }

        // ensuring that if a negative number has been input, nothing is printed
        if (newtime >= 0) {
            // printing the result!
            if (days > 0) {
                printf("%dd %dh %dm %ds \n", days, hours, mins, secs);
            }
            else if (hours > 0) {
                printf("%dh %dm %ds \n", hours, mins, secs);
            }
           
            else if (mins > 0) {
                printf("%dm %ds \n", mins, secs);
            }

            else {
                printf("%ds \n", secs);
            }
        }

    }

    printf("Done.\n");
    return 0;
}