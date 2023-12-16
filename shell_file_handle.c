#include "main.h"

/**
 * read_file - Reads commands from the argument File
 * @fcomm: File containing commands to be passed tp the shell
 * @argv: Arguments passed in function
 * Return: -1 or 0
 */

void read_file(char *fcomm, char **argv)
{
	FILE *finme;
	char *line = NULL;
	size_t len = 0;
	int ct = 0;

	finme = fopen(fcomm, "r");
	if (finme == NULL)
	{
		error_file(argv, ct);
		exit(127);
	}
	while ((getline(&line, &len, finme)) != -1)
	{
		ct++;
		treat_file(line, ct, finme, argv);
	}
	if (line)
		free(line);
	fclose(finme);
	exit(0);
}

/**
 * treat_file - Parse commands and handle their execution
 * @line: Line from file
 * @ct: Error counter
 * @filme: File descriptor
 * @argv: Command line arguments
 */
void treat_file(char *line, int ct, FILE *filme, char **argv)
{
	char **bltcmd;
	

	bltcmd = shell_parsecmd(line);
	if (_strncmp(bltcmd[0], "exit", 4) == 0)
		exit_bul_for_file(bltcmd, line, filme);
	else
	{
		check_cmd(bltcmd, line, ct, argv);
		free(bltcmd);
	}
}

/**
 * exit_bul_for_file - Exit status handler for file input
 * @line: Line from a file
 * @bltcmd: Parsed command
 * @finme: File Descriptor
 */
void exit_bul_for_file(char **bltcmd, char *line, FILE *finme)
{
	int status;
	int abc = 0;

	if (bltcmd[abc] == NULL)
	{
		free(line);
		free(bltcmd);
		fclose(finme);
		exit(errno);
	}
	while (bltcmd[1][abc])
	{
		if (_isalpha(bltcmd[1][abc++]) < 0)
			perror("Illegal number");
	}
	status = _atoi(bltcmd[1]);
	free(line);
	free(bltcmd);
	fclose(finme);
	exit(status);
}

