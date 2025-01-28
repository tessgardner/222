#include <stdio.h>

struct Person {
    int age;
    char name[20];
};

int main () {

    struct Person amanda = {20, "Amanda"};
    struct Person *amandaPtr = &amanda;

    printf("%s's age is %d\n", amandaPtr->name, amandaPtr->age);
    printf("%s's age is %d\n", (*amandaPtr).name, (*amandaPtr).age);


    return 0;
}