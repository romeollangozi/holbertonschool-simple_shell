#include "main.h"

void free_argum(char **argum, char *commandLine)
{
	int i = 0;
	(void) commandLine;
	while (argum[i])
	{
		free(argum[i]);
		i++;
	}
	free(argum);
}
int main()
{
        pid_t pid;
        char *commandLine = NULL, *delim = " \n";
        char **argum = NULL;
	int status = 0, exit_status = 0, chars = 0;
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
                        exit(exit_status);
		}
		if (chars == -1)
		{
			free(commandLine);
			exit(0);
		}
		argum = token_line(commandLine, delim);
		if (argum == NULL)
			{
				continue;
			}
                pid = fork();
                if (pid == 0)
                {
			execvp(argum[0], argum);
			perror("");
			free_argum(argum, commandLine);
			if (strcmp("",getenv("PATH")) == 0)
			{
				exit(127);
			}
				exit(2);
		}
                else
                {
                        waitpid(pid, &status, 0);
			if (WIFEXITED(status))
			{
				exit_status = WEXITSTATUS(status);
			}
			free_argum(argum, commandLine);
			continue;
                }
      }
	exit (0);
}
