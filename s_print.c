#include "main.h"

/**
 * print_number - Prints integers using _putchar function
 * @unint: Unsigned integer to be printed
 */
void print_number(unsigned int unint)
{
	unsigned int ui = unint;

	if ((ui / 10) > 0)
		print_number(ui / 10);

	_putchar(ui % 10 + '0');
}

/**
 * print_number_int - Prints integers using _putchar function
 * @nin: Integer to be printed
 */
void print_number_int(int nin)
{
	unsigned int ui = nin;

	if (nin < 0)
	{
		_putchar('-');
		ui = -ui;
	}
	if ((ui / 10) > 0)
		print_number(ui / 10);

	_putchar(ui % 10 + '0');
}

/**
 * print_echo - Executes built-in echo function
 * @bltcmd: Parsed Command
 * Return: 0 Upon Success -1 Upon Failure
 */
int print_echo(char **bltcmd)
{
	pid_t pid;
	int state;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", bltcmd, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}
	return (1);
}

