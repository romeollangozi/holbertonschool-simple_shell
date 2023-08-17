#include "main.h"
int main()
{
        pid_t pid;
        char *commandLine = NULL;
        char **argum = NULL;
	char *delim = " \n";
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
		{
			free(commandLine);	
                        exit(2);
		}
		if (chars == -1)
		{
			free(commandLine);
			exit(0);
		}
		argum = token_line(commandLine, delim);

			if (argum == NULL)
			{	
				free(argum);
				continue;
			}
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
					
					i = 0;
					while (argum[i])
					{
						free(argum[i]);
						i++;
					}
					free(argum);
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
			continue;
                }
		break;
      }
	exit (0);
}
