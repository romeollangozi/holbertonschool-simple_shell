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
					return (1);
			      }
                }
                else
                {
                        wait(NULL);
			free(argum);
			continue;
                }
		break;
      }
	return (0);
}
