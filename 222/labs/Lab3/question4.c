#include <stdio.h>

int main() {

    // instantiating variables
    float miles;
	float gallons;
    const float LITERS = 3.785;
    const float KM = 1.609;
	
    // getting input from user
	printf("Enter number of miles travelled: ");
	scanf("%f", &miles);
	printf("Enter number of gallons of gas used: " );
	scanf("%f", &gallons); 

    // doing all the calculations
    float mpg = miles / gallons;
    float lper100km = (100 * (gallons * LITERS)) / (miles * KM);

    // output!
    // used bito.ai/resources to figure out how to print past a certain number of decimals
    printf("Mile-per-gallon: %.2f \n", mpg); 
    printf("Liters-per-100-km: %.1f \n", lper100km);
    return 0;
}