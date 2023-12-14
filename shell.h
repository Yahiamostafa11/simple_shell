#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 


#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 100

void shell_loop(void);
void execute_command(char *tokens[]);
void handle_input(char *input);

#endif
