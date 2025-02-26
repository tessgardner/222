

#include <stdio.h>
#include <unistd.h>

int main(){

  // prints current directory
  char s[100];
  printf("%s$ ", getcwd(s, 100));
  chdir("..");
  printf("%s$ ", getcwd(s, 100));


  printf("\n");
  return 0;

}