#include <stdio.h>

int main(int argc, char *argv[]){
    

    if (argc < 3) {
        printf("Must provide at least 2 arguments.");
    } 
    else if (argc > 7) {
        printf("Must provide at most 6 arguments.\n");
    }
    else {
            for (int i=1; i < argc; i++){
        if (i % 2 == 0) {
            /*found an article on narkive(newsgroup archive) for how 
            to access individual char or a string in an array */
            printf("%c ", argv[i][0]);
        }
        else {
            printf("%c ", argv[i][1]);
        }
    }

    printf("\n");
    }
    
    return 0;
}