#include "main.h"

/**
 * shell_getline - read input from standard input by user
 * Return: the input on a buffer
 */
char *shell_getline()
{
	int i, see, buffsize = BUFSIZ;
	char c = 0, *bufr, *buf;

	bufr = malloc(buffsize);
	if (bufr == NULL)
	{
		free(bufr);
		return (NULL);
	}
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		see = read(STDIN_FILENO, &c, 1);
		if (see == 0)
		{
			free(bufr);
			exit(EXIT_SUCCESS);
		}
		bufr[i] = c;
		if (bufr[0] == '\n')
			return (enter(bufr));
		if (i >= buffsize)
		{
			bufr = realloc(bufr, (buffsize + 2));
			if (bufr == NULL)
			{
				free(bufr);
				return (NULL);
			}
		}
	}
	bufr[i] = '\0';
	buf = space(bufr);
	free(bufr);
	hashtag_handler(buf);
	return (buf);
}

/**
 * enter - Handles newline character input
 * @string: String to be handled
 * Return: Empty string
 */
char *enter(char *string)
{
	free(string);
	return ("\0");
}

/**
 * space - Modifies the input string to remove preceeding whitespaces
 * @str: Input to be modifies
 * Return: Returns the modified string
 */
char *space(char *str)
{
	int spc1, spc2 = 0;
	char *buff;

	buff = malloc(sizeof(char) * (_strlen(str) + 1));
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (spc1 = 0; str[spc1] == ' '; spc1++)
		;
	for (; str[spc1 + 1] != '\0'; spc1++)
	{
		buff[spc2] = str[spc1];
		spc2++;
	}
	buff[spc2] = '\0';
	if (buff[0] == '\0' || buff[0] == '#')
	{
		free(buff);
		return ("\0");
	}
	return (buff);
}

/**
 * hashtag_handler - function that removes everything after '#'
 * @buff: input buffer
 * Return: nothing
 */
void hashtag_handler(char *buff)
{
	int hash;

	for (hash = 0; buff[hash] != '\0'; hash++)
	{
		if (buff[hash] == '#' && buff[hash - 1] == ' ' && buff[hash + 1] == ' ')
		{
			buff[hash] = '\0';
		}
	}
}

