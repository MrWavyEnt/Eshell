#include "main.h"

/**
 * history - write file with user inputs
 * @in_u: Takes input from user
 * Return: 0 on success -1 if failed
 */
int history(char *in_u)
{
	char *filename = ".simple_shell_history";
	ssize_t finme, put;
	int length = 0;

	if (!filename)
		return (-1);
	finme = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (finme < 0)
		return (-1);
	if (in_u)
	{
		while (in_u[length])
			length++;
		put = write(finme, in_u, length);
		if (put < 0)
			return (-1);
	}
	return (1);
}

