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
		if (isatty(isatty(STDIN_FILENO)))
			printf("$");

                chars = getline(&commandLine, &max, stdin);
                if (strcmp(commandLine, "\n") == 0)
                        continue;
                if (strcmp(commandLine, "exit\n") == 0)
                        break;
		if (chars == -1)
			return(1);

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
					printf("%s: command not found\n", argum[0]);
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
	return (0);
}
