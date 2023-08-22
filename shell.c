#include "main.h"

/**
 * free_argum - function for freeing the memory allocation of the array
 * @argum: a pointer to an array
 */

void free_argum(char **argum)
{
	int i = 0;

	while (argum[i])
	{
		free(argum[i]);
		i++;
	}
	free(argum);
}

/**
 * execute - function to execute a command with its arguments
 * @status: a pointer that will hold the exit status of the child process
 * @pid: process ID of the child process
 * @argum: pointer to an array of commands and its arguments
 * @commandLine: command input
 * @exit_status: exit status of the program
 */

void execute(int *status, pid_t pid, char **argum, char *commandLine,
		int *exit_status)
{
	if (pid == 0)
	{
		execvp(argum[0], argum);
		perror(NULL);
		free(commandLine);
		free_argum(argum);
		exit(127);
	}
	else
	{
		waitpid(pid, status, 0);
		if (WIFEXITED(*status))
		{
			*exit_status = WEXITSTATUS(*status);
		}
		free_argum(argum);
		return;
	}
}

/**
 * main - Entry point
 * Return: Always 0
 */

int main(void)
{
	pid_t pid;
	char *commandLine = NULL, *delim = " \n", **argum = NULL;
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
			return (exit_status);
		}
		if (chars == -1)
		{
			free(commandLine);
			exit(0);
		}
		argum = token_line(commandLine, delim);
		if (argum == NULL)
			continue;

		pid = fork();
		execute(&status, pid, argum, commandLine, &exit_status);
	}
	exit(0);
}
