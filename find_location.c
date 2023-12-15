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

char *find_location(char *command)
{
	char *path, *path_cpy, *path_token, *file_path;
	int command_len, directory_len;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		path_cpy = strdup(path);
		command_len = strlen(command);
		path_token = strtok(path_cpy, ":");
		while (path_token != NULL)
		{
			directory_len = strlen(path_token);
			file_path = malloc(command_len + directory_len + 2);

			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_cpy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_cpy);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
