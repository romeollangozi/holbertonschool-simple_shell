#ifndef MAIN.H
#define MAIN.H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include<sys/wait.h>
#include <stdlib.h>

extern char *path = getenv("PATH")
char *token_path(char *command);
char **token_line(char *comand_line, char *delim);

#endif
