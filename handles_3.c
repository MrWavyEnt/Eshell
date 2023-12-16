#include "main.h"

/**
 * _strcmp - function that compares two string
 * @strg1: first string
 * @strg2: second string
 * Return: 0 if identical otherwise how much diffrent
 */
int _strcmp(char *strg1, char *strg2)
{
	int cmp = 0, i, l1, l2;

	l1 = _strlen(strg1);
	l2 = _strlen(strg2);

	if (strg1 == NULL || strg2 == NULL)
		return (1);

	if (l1 != l2)
		return (1);

	for (i = 0; strg1[i]; i++)
	{
		if (strg1[i] != strg2[i])
		{
			cmp = strg1[i] - strg2[i];
			break;
		}
		else
			continue;

	}
	return (cmp);
}

/**
 * _isalpha - function to check if c is alphabet
 * @isa: character to check
 * Return: 1 if true 0 if false
 */
int _isalpha(int isa)
{
	if (((isa >= 97) && (isa <= 122)) || ((isa >= 65) && (isa <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _itoa - funciton that convert integer to character
 * @ia: integer to convert
 * Return: character pointer
 */
char *_itoa(unsigned int ia)
{
	int lent = 0, i = 0;
	char *son;

	lent = intlen(ia);
	son = malloc(lent + 2);

	if (!son)
	{
		free(son);
		return (NULL);
	}
	*son = '\0';

	while (ia / 10)
	{
		son[i] = (ia % 10) + '0';
		ia /= 10;
		i++;
	}

	son[i] = (ia % 10) + '0';
	array_rev(son, lent);
	son[i + 1] = '\0';

	return (son);
}

/**
 * array_rev - function reverse an array
 * @ary: array to reverse
 * @lent: length of array
 */
void array_rev(char *ary, int lent)
{
	int i;
	char tmo;

	for (i = 0; i < (lent / 2); i++)
	{
		tmo = ary[i];
		ary[i] = ary[(lent - 1) - i];
		ary[(lent - 1) - i] = tmo;
	}
}

/**
 * intlen - function that determine length of integer
 * @lentnum: given integer
 * Return: length of integer
 */
int intlen(int lentnum)
{
	int len = 0;

	while (lentnum != 0)
	{
		len++;
		lentnum /= 10;
	}
	return (len);
}

