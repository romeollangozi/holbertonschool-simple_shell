#include "main.h"

/**
 * token_path - function to tokenize the path env
 * @path: path
 * @delim: delimits the tokens in the string
 * @filename: filename to be attached
 * Return: array of tokens
 */

char **token_path(char *path, char *delim, char *filename)
{
	char *token;
	int num_tokens = 0;
	char *path_copy;
	char *file;
	char *ch = "/";
	char **argv;
	int i;
	
	path_copy = malloc(sizeof(char) * strlen(path));
	strcpy(path_copy, path);
	token = strtok(path, delim);
	
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}

	num_tokens++;
	argv = malloc(sizeof(char*) * num_tokens);
	token = strtok(path_copy, delim);
	file = malloc(sizeof(char) * strlen(filename) + strlen(ch));
	strcpy(file, ch);
	strcat(file, filename);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token) + strlen(file));
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	for (i = 0; argv[i] != NULL; i++)
	{
		strcat(argv[i], file);
	}
	
	printf("%lu\n", sizeof(argv));
	return (argv);
}
