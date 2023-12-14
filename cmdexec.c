#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * cmdexec - Executes a command specified by the argv array
 * using the execve system call.
 * @argv: Array of strings representing the command and it's arguments
 * Return: NULL
 */
void cmdexec(char **argv)
{
	char *command = NULL, *actual_command = NULL;

	if (argv)
	{
		command = argv[0];

		if (strcmp(command, "env") == 0)
		{
			print_environment();
			return;
		}

		actual_command = find_location(command);

		if (execve(actual_command, argv, NULL) == -1)
		{
			PERROR("Error:");
		}
	}
}

/**
 * print_environment - Prints the current environment variables
 * Return: NULL
 */
void print_environment(void)
{
	int i = 0;
	extern char **environ;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
