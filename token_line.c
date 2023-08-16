#include "main.h"

/**
 * token_line - function to tokenize the command line
 * @command_line: input command
 * @delim: delimits the tokens in the string
 * Return: array of tokens
 */

char **token_line(char *command_line, char *delim)
{
	char *token;
	int num_tokens = 0;
	char *command_line_copy;
	char **argv;
	int i;
	
	strcpy(command_line_copy, command_line);
	token = strtok(command_line, delim);
	
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;
	argv = malloc(sizeof(char*) * num_tokens);
	
	token = strtok(command_line_copy, delim);
	
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	return (argv);
}
