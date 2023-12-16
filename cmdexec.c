#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_environment(void);

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

			if (execve(actual_command, argv, get_environ()) == -1)
		{
			perror("Error:");
		}
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
	char *const *environ = get_environ();

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
 * get_environ - Gets the current environment variables.
 * Return: A pointer to the first element of the environ array.
 */
char **get_environ(void)
{
	extern char **environ;
	return environ;
}
                  
