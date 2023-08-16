#include "main.h"
int main()
{
        pid_t pid;
        char *commandLine;
        char **argum;
	int chars;
	size_t max = MAX_CHARS;	
        while (1)
        {

		printf("$");
                chars = getline(&commandLine, &max, stdin);

                if (strcmp(commandLine, "\n") == 0)
                        continue;
                if (strcmp(commandLine, "exit\n") == 0)
                        break;
		if (chars == -1)
			break;

                if (commandLine[chars - 1] == '\n')
                        commandLine[chars - 1] = '\0';
		
		argum = token_line(commandLine, " \n");
                pid = fork();
                if (pid == 0)
                {
                                execvp(argum[0], argum);
                }
                else
                {
                        wait(NULL);
			free(argum);
                }
      }
	return (0);
}
