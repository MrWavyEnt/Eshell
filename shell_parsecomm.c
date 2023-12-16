#include "main.h"

/**
 * shell_parsecmd - Parses the command received from stdin to the shell
 * @ustring: String gathered from stdin by user
 * Return: Parsed strings to be used as arguments
 */
char **shell_parsecmd(char *ustring)
{
	char **value;
	char *vals;
	int abc;
	int buffsize = BUFSIZ;

	if (ustring[0] == ' ' && ustring[_strlen(ustring)] == ' ')
		exit(0);
	if (ustring == NULL)
		return (NULL);
	value = malloc(sizeof(char *) * buffsize);
	if (!value)
	{
		free(value);
		perror("hsh");
		return (NULL);
	}
	vals = _strtok(ustring, "\n\t\r\a ");
	for (abc = 0; vals; abc++)
	{
		value[abc] = vals;
		vals = _strtok(NULL, "\n\t\r\a ");
	}
	value[abc] = NULL;

	return (value);
}

