#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include<sys/wait.h>
#include <stdlib.h>
int main()
{
        while (1)
        {
        pid_t pid;
        char *commandLine;
        size_t size = 100;
        char *argum[3];
        char *token;
        char *filename;
        char *delim = " ";
        int i = 1;
        int chars;
        char path[50] = "/bin/";
                printf("$");
                commandLine = malloc(size);
                chars = getline(&commandLine, &size, stdin);
                if (strcmp(commandLine, "\n") == 0)
                        continue;
                if (strcmp(commandLine, "exit\n") == 0)
                        break;
                if (commandLine[chars - 1] == '\n')
                        commandLine[chars - 1] = '\0';
                argum[0] = strtok(commandLine, delim);
                filename = argum[0];
               while ((token = strtok(NULL, delim)) != NULL)
               {
                        argum[i] = token;
                        i++;
               }
               argum[i] = NULL;
               strcat(path, filename);
                pid = fork();
                if (pid == 0)
                {
                                execvp(filename, argum);
                }
                else
                {
                        wait(NULL);
                        i = 0;
                }
      }
	return (0);
}
