#include "main.h"

/**
 * sept - Separates command recieved from stdin by ;
 * @in_s: String gathered from stdin
 * Return: Parsed strings to be used as commands
 */
char **sept(char *in_s)
{
	char **comd;
	char *comm;
	int abc;
	int buffsize = BUFSIZ;

	if (in_s[0] == ' ' && in_s[_strlen(in_s)] == ' ')
		exit(0);
	if (in_s == NULL)
		return (NULL);
	comd = malloc(sizeof(char *) * buffsize);
	if (!comd)
	{
		free(comd);
		perror("hsh");
		return (NULL);
	}
	comm = _strtok(in_s, ";&");
	for (abc = 0; comm; abc++)
	{
		comd[abc] = comm;
		comm = _strtok(NULL, ";&");
	}
	comd[abc] = NULL;

	return (comd);
}

