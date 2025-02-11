#include <unistd.h>

int main(){
    // example of execl
    execl("/bin/ls", "ls", "-al", "-h", NULL);
}