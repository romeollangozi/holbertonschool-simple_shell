#include "main.h"
int main()
{
        pid_t pid;
        char *commandLine = NULL;
        char **argum = NULL;
	int chars = 0;
	int i = 0;
	size_t max = MAX_CHARS;	
        while (1)
        {
		if (isatty(STDIN_FILENO))
			printf("$");

                chars = getline(&commandLine, &max, stdin);
                if (strcmp(commandLine, "\n") == 0)
                        continue;
                if (strcmp(commandLine, "exit\n") == 0)
                        exit(0);
		if (chars == -1)
			exit(0);

		argum = token_line(commandLine, " \n");
		if (strcmp("cd", argum[0]) == 0)
		{
			chdir(argum[1]);
			continue;
		}
                pid = fork();
                if (pid == 0)
                {
                              if(execvp(argum[0], argum))
			      {
					perror("%s: command not found\n");
					continue;
			      }
                }
                else
                {
                        wait(NULL);
			i = 0;
			while (argum[i])
			{
				free(argum[i]);
				i++;
			}
			free(argum);
			free(commandLine);
			continue;
                }
		break;
      }
	exit (0);
}
