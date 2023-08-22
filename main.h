#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>
#define MAX_CHARS 1024
extern char **environ;
char **token_path(char *path, char *delim, char *filename);
char **token_line(char *comand_line, char *delim);
char *command_path(char *cmd);
#endif
