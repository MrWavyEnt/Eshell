#include "main.h"
#include <stdlib.h>
/**
 * find_location - Finds the location of a command in the PATH
 * @command: The command to find
 * This function searches for the location of a command in the PATH. It
 * returns a pointer to the location of the command if it is found, or
 * NULL if it is not found or if an error occurs.
 * Return: A pointer to the location of the command, or NULL.
 */
char *find_location(const char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;

	path = getenv("PATH");

	if (path == NULL || command == NULL)
	{
		return (NULL);
	}
	path_copy = strdup(path);
	command_length = strlen(command);
	path_token = strtok(path_copy, ":");

	while (path_token != NULL)
	{
		directory_length = strlen(path_token);
		file_path = malloc(command_length + directory_length + 2);
		if (file_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		strcpy(file_path, path_token);
		strcat(file_path, "/");
		strcat(file_path, command);
		if (access(file_path, X_OK) == 0)
		{
		free(path_copy);
		return (file_path);
		}
		free(file_path);
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
	if (access(command, X_OK) == 0)
	{
		return (strdup(command));
	}
	return (NULL);
}
