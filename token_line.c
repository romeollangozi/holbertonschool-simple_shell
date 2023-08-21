#include "main.h"

/**
 * token_line - function to tokenize the command line
 * @command_line: input command
 * @delim: delimits the tokens in the string
 * Return: array of tokens
 */

char  **token_line(char *command_line, char *delim)
{
	char *token = NULL;
	int num_tokens = 0;
	char *command_line_copy = NULL;
	char **argv = NULL;
	int i = 0;

	command_line_copy = malloc(sizeof(char) * strlen(command_line) + 1);
	strcpy(command_line_copy, command_line);
	token = strtok(command_line, delim);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	if (num_tokens == 0)
	{
		free(command_line_copy);
		return (NULL);
	}
	num_tokens++;
	argv = malloc(sizeof(char *) * num_tokens);
	token = strtok(command_line_copy, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token) + 1);
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	free(command_line_copy);
	argv[i] = NULL;
	return (argv);
}
