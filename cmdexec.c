#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void print_environment(void);

extern char **environ;

/**
 * handle_exit - handles the "exit" built-in command.
 * Prints a farewell message and exits the shell.
 * Return: NULL
 */
void handle_exit(void)
{
	printf("Exiting the shell, Goodbye!\n");
	exit(0);
}

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

		if (strcmp(command, "exit") == 0)
		{
			handle_exit();
		}

		else if (strcmp(command, "env") == 0)
		{
			print_environment();
		}
		else
		{
			actual_command = find_location(command);

			if (execve(actual_command, argv, NULL) == -1)
		{
			PERROR("Error:");
		}
		}
	}
}

/**
 * print_environment - Prints the current environment variables.
 * Return: NULL
 */
void print_environment(void)
{
	extern char **environ;

	 char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
