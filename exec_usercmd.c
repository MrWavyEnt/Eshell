#include "main.h"

/**
 * exec_usercmd - executes commands passed by user
 * @args: the character string to be executed
 *
 * Return: void
 */
void exec_usercmd(char **args)
{
	int status;
	pid_t kind_pid = fork();

	if (kind_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (kind_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
