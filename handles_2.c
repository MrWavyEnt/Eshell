#include "main.h"

/**
 * _strcpy - function that copies a string
 * @destint: destination
 * @srcstr: source
 * Return: destination
 */
char *_strcpy(char *destint, char *srcstr)
{
	int i = 0;

	while (srcstr[i])
	{
		destint[i] = srcstr[i];
		i++;
	}
	destint[i] = '\0';
	return (destint);
}

/**
 * _strcat - function that concatenates two strings
 * @destint: first string
 * @srcstr: second string
 * Return: first string + second string
 */
char *_strcat(char *destint, char *srcstr)
{
	char *so = destint;

	while (*destint != '\0')
	{
		destint++;
	}

	while (*srcstr != '\0')
	{
		*destint = *srcstr;
		destint++;
		srcstr++;
	}
	*destint = '\0';
	return (so);
}

/**
 * _strchr - function that locates character in a string
 * @sin: string to be searched
 * @chr: character to be located
 * Return: pointer to character
 */
char *_strchr(char *sin, char chr)
{
	do {
		if (*sin == chr)
		{
			break;
		}
	} while (*sin++);
	return (sin);
}

/**
 * _strncmp - function that compares n amount of characters of two strings
 * @strg1: first string
 * @strg2: second string
 * @nchr: amount of characters to compare
 * Return: 1 if the strings don't match otherwise 0
 */
int _strncmp(const char *strg1, const char *strg2, size_t nchr)
{
	size_t i;

	if (strg1 == NULL)
		return (-1);

	for (i = 0; i < nchr && strg2[i]; i++)
	{
		if (strg1[i] != strg2[i])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _strdup - duplicate a string
 * @string: string
 * Return: duplicated string or Null if failed
 */
char *_strdup(char *string)
{
	size_t lent, i;
	char *str2;

	lent = _strlen(string);
	str2 = malloc(sizeof(char) * (lent + 1));
	if (!str2)
	{
		return (NULL);
	}
	for (i = 0; i <= lent; i++)
	{
		str2[i] = string[i];
	}
	return (str2);
}

