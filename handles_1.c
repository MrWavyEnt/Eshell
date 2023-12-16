#include "main.h"

/**
 * _putchar - function that writes the character to stdout
 * @i: The character to print
 * Return: character to standard output
 */

int _putchar(char i)
{
	return (write(1, &i, 1));
}


/**
 * _puts - function that prints a string
 * @string: pointer to string
 * Return: void
 */
void _puts(char *string)
{
	int a;

	for (a = 0; string[a] != '\0'; a++)
	{
		_putchar(string[a]);
	}
	_putchar('\n');
}

/**
 * _strncpy - function that copies a string
 * @destint: destination string
 * @srcstr: source string
 * @c: number of charaters to be copied
 * Return: copied strings
 */
char *_strncpy(char *destint, char *srcstr, int c)
{
	int i = 0;

	while (i < c && *(srcstr + i))
	{
		*(destint + i) = *(srcstr + i);
		i++;
	}
	while (i < c)
	{
		*(destint + i) = '\0';
		i++;
	}
	return (destint);
}

/**
 * _strlen - function that counts the length of a string
 * @sin: string input
 * Return: length of string
 */
int _strlen(char *sin)
{
	int a;

	for (a = 0; sin[a] != '\0'; a++)
	{
		continue;
	}
	return (a);
}

/**
 * _atoi - function to convert string to a integer
 * @ai: string input
 * Return: converted integer
 */
int _atoi(char *ai)
{
	int i = 0, j = 1, k;
	unsigned int l = 0;

	while (ai[i] != '\0')
	{
		if (ai[i] == '-')
		{
			return (2);
		}
		k = ai[i] - '0';

		if (l > 0 && !(k >= 0 && k <= 9))
			break;

		if (k >= 0 && k <= 9)
			l = l * 10 + k;

		i++;
	}
	l *= j;
	return (l);
}

