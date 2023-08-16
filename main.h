#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_CHARS 1024
char *token_path(char *command);
char **token_line(char *comand_line, char *delim);

#endif
