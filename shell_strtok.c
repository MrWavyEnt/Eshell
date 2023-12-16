#include "main.h"

/**
 * delim_chk - function that checks if a character matchs any character
 * @c: character to check
 * @delstr: string of delimiters
 * Return: 1 on success, 0 on failure
 */
unsigned int delim_chk(char c, const char *delstr)
{
	unsigned int i;

	for (i = 0; delstr[i] != '\0'; i++)
	{
		if (c == delstr[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - function that extracts tokens of a string
 * @str: to be examined string
 * @delimit: delimiter to extract from
 * Return: pointer to the next token or NULL
 */
char *_strtok(char *str, const char *delimit)
{
	static char *tkn;
	static char *new_token;
	unsigned int i;

	if (str != NULL)
		new_token = str;
	tkn = new_token;
	if (tkn == NULL)
		return (NULL);
	for (i = 0; tkn[i] != '\0'; i++)
	{
		if (delim_chk(tkn[i], delimit) == 0)
			break;
	}
	if (new_token[i] == '\0' || new_token[i] == '#')
	{
		new_token = NULL;
		return (NULL);
	}
	tkn = new_token + i;
	new_token = tkn;
	for (i = 0; new_token[i] != '\0'; i++)
	{
		if (delim_chk(new_token[i], delimit) == 1)
			break;
	}
	if (new_token[i] == '\0')
		new_token = NULL;
	else
	{
		new_token[i] = '\0';
		new_token = new_token + i + 1;
		if (*new_token == '\0')
			new_token = NULL;
	}
	return (tkn);
}

