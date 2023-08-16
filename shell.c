#include "main.h"
int main()
{
        pid_t pid;
        char *commandLine;
        char **argum;
	char **patharg;
	int chars;
	size_t max = MAX_CHARS;
	char *path;

        while (1)
        {
		
		path = getenv("PATH");
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
		patharg = token_path(path, ":", argum[0]);
                pid = fork();
                if (pid == 0)
                {
                                execve(argum[0], argum, NULL);
                }
                else
                {
                        wait(NULL);
			free(argum);
                }
      }
	return (0);
}
