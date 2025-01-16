#include <stdio.h>

int main(int argc, char *argv[]){
    // ^ a standard signature for taking in command line arguments
    // argc represents the number of arguments coming in. 
    // argv a pointer to where the arguments are stored in memory
    
    // printing the inputs
    printf("argc: %d\n", argc);
    
    for (int i=0; i < argc; i++){
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    // argv ends with a null pointer
    printf("argv[%d]: %s\n", argc, argv[argc]);

    return 0;
}