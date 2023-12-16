#include "main.h"

/**
 * path_find -  Search In $PATH for executable command
 * @bltcmd: Parsed input
 * Return: 0 on success or  1 on failure  0
 */
int path_find(char **bltcmd)
{
	char *path, *num, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	num = _strtok(path, ":");
	while (num != NULL)
	{
		cmd_path = build(*bltcmd, num);
		if (stat(cmd_path, &buf) == 0)
		{
			*bltcmd = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		num = _strtok(NULL, ":");
	}
	free(path);
	free(num);
	return (1);
}

/**
 * build - Build command
 * @token: Executable command
 * @value: Directory conatining Command
 * Return: Parsed full path of command or NULL if failed
 */
char *build(char *tkn, char *num)
{
	char *bltcmd;
	size_t len;

	len = _strlen(num) + _strlen(tkn) + 2;
	bltcmd = malloc(sizeof(char) * len);
	if (bltcmd == NULL)
	{
		free(bltcmd);
		return (NULL);
	}

	memset(bltcmd, 0, len);

	bltcmd = _strcat(bltcmd, num);
	bltcmd = _strcat(bltcmd, "/");
	bltcmd = _strcat(bltcmd, tkn);

	return (bltcmd);
}

/**
 * _getenv - Gets the value of environment variable by name
 * @evinm: Environment variable name
 * Return: The value of the environment variable or NULL if failed
 */
char *_getenv(char *envinm)
{
	size_t lenname, lenval;
	char *value;
	int a, b, c;

	lenname= _strlen(envinm);
	for (a = 0 ; environ[a]; a++)
	{
		if (_strncmp(envinm, environ[a], lenname) == 0)
		{
			lenval = _strlen(environ[a]) - lenname;
			value = malloc(sizeof(char) * lenval);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			b = 0;
			for (c = lenname + 1; environ[a][c]; c++, b++)
			{
				value[b] = environ[a][c];
			}
			value[b] = '\0';

			return (value);
		}
	}
	return (NULL);
}

