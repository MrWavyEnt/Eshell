#include "main.h"

/**
 * main - The main function that includes all functions needed for the shell
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Returns condition
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *in_u, **bltcmd, **comd;
	int ct = 0, abc, condition = 1, stat = 0;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, signal_to_handle);
	while (condition)
	{
		ct++;
		if (isatty(STDIN_FILENO))
			prompt();
		in_u = shell_getline();
		if (in_u[0] == '\0')
			continue;
		history(in_u);
		comd = sept(in_u);
		for (abc = 0; comd[abc] != NULL; abc++)
		{
			bltcmd = shell_parsecmd(comd[abc]);
			if (_strcmp(bltcmd[0], "exit") == 0)
			{
				free(comd);
				exit_bul(bltcmd, in_u, argv, ct, stat);
			}
			else if((stat = check_cmd(bltcmd, in_u, ct, argv)))
			{
				free(bltcmd);
			}
			else 
			{
				continue;
			}
		}
		free(in_u);
		free(comd);
		wait(&stat);
	}
	return (stat);
}

