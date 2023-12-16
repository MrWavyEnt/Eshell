#include "main.h"

/**
 * change_dir - Changes directory
 * @bltcmd: builtin parsed command
 * @statl: Status of last command executed
 * Return: 0 on success 1 if failed (For OLDPWD Always 0 incase of no OLDPWD)
 */
int change_dir(char **bltcmd, __attribute__((unused))int statl)
{
	int val = -1;
	char cwd[PATH_MAX];

	if (bltcmd[1] == NULL)
		val = chdir(getenv("HOME"));
	else if (_strcmp(bltcmd[1], "-") == 0)
	{
		val = chdir(getenv("OLDPWD"));
	}
	else
		val = chdir(bltcmd[1]);

	if (val == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (val != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * dis_env - Display enviroment variable
 * @bltcmd: builtin parsed command
 * @statl: status of last command executed
 * Return: Always 0
 */
int dis_env(__attribute__((unused)) char **bltcmd, __attribute__((unused)) int statl)
{
	size_t in;
	int len;

	for (in = 0; environ[in] != NULL; in++)
	{
		len = _strlen(environ[in]);
		write(1, environ[in], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * echo_bul - execute echo cases
 * @statl: statue of last command executed
 * @bltcmd: bultin parsed command
 * Return: Always 1 Or execute normal echo
 */
int echo_bul(char **bltcmd, int statl)
{
	char *path;
	unsigned int pid = getppid();

	if (_strncmp(bltcmd[1], "$?", 2) == 0)
	{
		print_number_int(statl);
		PRINT("\n");
	}
	else if (_strncmp(bltcmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINT("\n");
	}
	else if (_strncmp(bltcmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINT(path);
		PRINT("\n");
		free(path);
	}
	else
		return (print_echo(bltcmd));

	return (1);
}

/**
 * history_dis - display history of user input on simple_shell
 * @c: parsed command
 * @statl: status of last command executed
 * Return: 0 success or -1 if fail
 */
int history_dis(__attribute__((unused))char **c, __attribute__((unused))int statl)
{
	char *filename = ".simple_shell_history";
	FILE *finme;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
	char *chrr;

	finme = fopen(filename, "r");
	if (finme == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &len, finme)) != -1)
	{
		counter++;
		chrr = _itoa(counter);
		PRINT(chrr);
		free(chrr);
		PRINT(" ");
		PRINT(line);
	}
	if (line)
		free(line);
	fclose(finme);
	return (0);
}

