#include "main.h"
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

		actual_command = find_location(command);

		if (execve(actual_command, argv, NULL) == -1)
		{
			PERROR("Error:");
		}
	}
}
