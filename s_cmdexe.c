#include "main.h"

/**
 * check_cmd - Excutes commands found in predefined path
 * @bltcmd: Array of parsed command strings
 * @in_u: Input recieved from user (to be freed)
 * @shexc:Shell Excution Time Case of Command Not Found
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */
int check_cmd(char **bltcmd, char *in_u, int shexc, char **argv)
{
	int ws;
	pid_t pid;

	if (*bltcmd == NULL)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (_strncmp(*bltcmd, "./", 2) != 0 && _strncmp(*bltcmd, "/", 1) != 0)
			path_find(bltcmd);
		if (access(bltcmd[0], R_OK) != 0)
		{
			print_error(bltcmd[0], shexc, argv);
			free_all(bltcmd, in_u);
			exit(127);
		}
		if (execve(*bltcmd, bltcmd, environ) == -1)
			return (2);
		else
			return (0);
	}
	wait(&ws);
	if (WIFEXITED(ws))
	{
		if (WEXITSTATUS(ws) == 0)
			return (0);
		else if (WEXITSTATUS(ws) == 2)
			return (2);
		else if (WEXITSTATUS(ws) == 127)
			return (127);
	}
	return (127);
}

/**
 * signal_to_handle - Configures ^C not to terminate our shell
 * @signil: Incoming Signal
 */
void signal_to_handle(int signil)
{
	if (signil == SIGINT)
	{
		PRINT("\n$ ");
	}
}

