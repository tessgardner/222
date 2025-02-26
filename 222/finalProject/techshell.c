/*
* Name(s): Tess Gardner
* Date: 2/27/2025
* Program Description: Write a C program that repeatedly allows a user to enter input. 
  Your program should provide an informative shell prompt that contains the current working directory, 
  followed by a $, and ending with a space. The prompt should be updated if the current working directory 
  changes. You must also include output from testing your program using script
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX 20

struct ShellCommand;

struct ShellCommand {

  char *instructions[10]; //actual commands themselves
  char *flags[10];
  char *redirect[10];
  char *fdirs[10]; // files, directories, etc
  char *outputs[10];
};

// Display current working directory and return user input
char* CommandPrompt() {

  // allocating memory for shell input
  char *c_input = malloc(100);  
  char s[100];

  // current path
  printf("%s$ ", getcwd(s, sizeof(s)));

  // asks for user input
  fgets(c_input, 100, stdin);

  // getting rid of null terminator
  c_input[strcspn(c_input, "\n")] = '\0';

  // returns the input to be parsed
  return c_input;
}

// Process the user input (As a shell command)
struct ShellCommand ParseCommandLine(char* input) { 

  char* poscommands[] = {"cd", "pwd", "ls", "mkdir", "touch", "rmdir", "rm", "wget", "wc", "cat", "chmod","ps", "whereis", "exit"};
  char* flagcommands[] = {"-a", "-l", "-h", "-R", "-t", "-i", "-E", "-v", "-r", "-f","-i", "-o", "u"};
  char* redirects[] = {"<", ">", "|"};
  size_t pcount = sizeof(poscommands) / sizeof(poscommands[0]); 
  size_t fcount = sizeof(flagcommands) / sizeof(flagcommands[0]); 
  size_t rcount = sizeof(redirects) / sizeof(redirects[0]); 



  struct ShellCommand command = {0};
  
  int commandct = 0; // count of commands
  int flagct = 0;
  int fdirsct = 0; // count of files, directories, etc
  int redirect_ct = 0;
  int outputct = 0;


  bool isCommand = false; // true if arg is a command
  bool isFlag = false; // true if arg is a flag
  bool isDirect = false; // true if redirection is detected


  // did research to split a string up and found an article on strtok() on GeeksForGeeks
  char* token = strtok(input, " ");

  while (token != NULL) {

    isCommand = false;
    isFlag = false; 

    for(int i = 0; i < pcount; i++) {
      if ((strcmp(token, poscommands[i]) == 0)) {
        command.instructions[commandct] = strdup(token);
        commandct++;
        isCommand = true;
        break;
      }

    }

    for(int i = 0; i < fcount; i++) {
      if ((strcmp(token, flagcommands[i]) == 0)) {
        command.flags[flagct] = malloc(strlen(token) + 1);  // Allocate memory for command
        strncpy(command.flags[flagct], token, strlen(token) + 1); // Copy the token
        flagct++;
        isFlag = true;
        break;
      }

    }

      for(int i = 0; i < rcount; i++) {
      if ((strcmp(token, redirects[i]) == 0)) {
        command.redirect[redirect_ct] = strdup(token);  // Allocate memory for command
        redirect_ct++;
        isDirect = true;
        token = strtok(NULL, " ");

        if (token != NULL) {
          command.redirect[__FD_SETSIZE] = strdup(token);  // Allocate memory for command
          fdirsct++;
        }
            break;
      }

    }


    if (isCommand == false && isFlag == false && isDirect == false) {

      command.fdirs[fdirsct] = malloc(strlen(token) + 1);  // Allocate memory for command
      strncpy(command.fdirs[fdirsct], token, strlen(token) + 1); // Copy the token

      fdirsct++;
    }


    if (isDirect == true) {

      command.outputs[outputct] = malloc(strlen(token) + 1);  // Allocate memory for command
      strncpy(command.outputs[outputct], token, strlen(token) + 1); // Copy the token

      outputct++;
    }


    token = strtok(NULL, " ");
  }

  command.instructions[commandct] = NULL;

  return command;
}

//Execute a shell command
void ExecuteCommand(struct ShellCommand command) {
  char *args[MAX];
  int arg_Index = 0;

  if (command.instructions[0] == NULL) {
    return;
  }
  

  args[arg_Index] = command.instructions[0];
  arg_Index++;

  for (int i = 0; command.flags[i] != NULL; i++) {
    args[arg_Index] = command.flags[i];
    arg_Index++;
  }

    for (int i = 0; command.fdirs[i] != NULL; i++) {
      args[arg_Index] = command.fdirs[i];
      arg_Index++;
  }

  args[arg_Index] = NULL;

  // if command = cd
  if (strcmp(command.instructions[0], "cd") == 0) {
    chdir(command.fdirs[0]);
    return;
  }


  int pid = fork();

  if (pid < 0){
      printf("Failed to create child process\n");
      return;
  }
  if (pid == 0) {
    if (command.redirect[0] != NULL && strcmp(command.redirect[0], ">") == 0) {
      FILE* outfile = fopen(command.outputs[0], "w");
      if (outfile == NULL) {
        perror("fail");
        exit(EXIT_FAILURE);
      }
      dup2(fileno(outfile), 1);
      fclose(outfile);
    }

    if (command.redirect[0] != NULL && strcmp(command.redirect[0], "<") == 0) {
      FILE* infile = fopen(command.outputs[0], "r"); 
      if (infile == NULL) {
        perror("fail");
        exit(EXIT_FAILURE);
      }
      dup2(fileno(infile), 0);
      fclose(infile);
    }

    /*
    if (command.redirect[0] != NULL && strcmp(command.redirects[0], "|") == 0) {
    }
    */ 

    execvp(args[0], args);
    perror("execvp failed");
    exit(EXIT_FAILURE);
  } else {
    // wait for child to finish
    wait(NULL); 
  }
}

int main() { 

  char* input;
  struct ShellCommand command;

  // repeatedly prompt the user for input
  for (;;) {

    input = CommandPrompt();

    // parse the command line
    command = ParseCommandLine(input);

    // execute the command
    ExecuteCommand(command);

  }
  exit(0);
}
