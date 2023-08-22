#include "main.h"
/**
 * command_path - func that finds the path from environ
 * @cmd: comand
 * Return: full path
 */
char *command_path(char *cmd)
{
	char *path = strdup(getenv("PATH")), *token = strtok(path, ":");
	char *path_array[100], *new_path = NULL;
	struct stat buf;
	int i = 0;

	new_path = malloc(sizeof(char) * 100);
	while (token != NULL)
	{
		path_array[i] = token;
		i++;
		token = strtok(NULL, ":");
	}
	path_array[i] = NULL;
	for (i = 0; path_array[i]; i++)
	{
		strcpy(new_path, path_array[i]);
		strcat(new_path, "/");
		strcat(new_path, cmd);
		strcat(new_path, "\0");
		if (stat(new_path, &buf) == 0)
		{
			free(path);
			return (new_path);
		}
		else
			new_path[0] = 0;
	}
	if (stat(cmd, &buf) == 0)
	{
		free(new_path);
		free(path);
		return (strdup(cmd));
	}
	free(new_path);
	free(path);
	return (NULL);
}
