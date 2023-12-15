#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void print_environment(void);

/**
 * handle_exit - handles the "exit" built-in command.
 * Prints a farewell message and exits the shell.
 * @status: Exit status to be returned to the operating system.
 * Return: Does not return.
 */
void handle_exit(int status)
{
	printf("Exiting the shell with status %d. Goodbye!\n", status);
	exit(status);;
}

/**
 * cmdexec - Executes a command specified by the argv array
 * using the execve system call.
 * @argv: Array of strings representing the command and it's arguments
 * Return: Does not return on success. Exits the process if an error occurs.
 */
void handle_exit(int status)
{
   printf("Exiting the shell with status %d. Goodbye!\n", status);
   exit(status);
}

void cmdexec(char **argv)
{
   char *command = NULL, *actual_command = NULL;
   pid_t pid;
   int exit_status;

   if (argv)
   {
       command = argv[0];

       if (strcmp(command, "exit") == 0)
       {
           handle_exit(0);
       }
       else if (strcmp(command, "env") == 0)
       {
           print_environment();
       }
       else
       {
           actual_command = find_location(command);

           pid = fork();
           if (pid == -1)
           {
               perror("Error:");
               return;
           }
           else if (pid > 0)
           {
               waitpid(pid, &exit_status, 0);
           }
           else
           {
               if (execve(actual_command, argv, get_environ()) == -1)
               {
                  perror("Error:");
                  exit(EXIT_FAILURE);
               }
           }
       }
   }
}


/**
 * print_environment - Prints the current environment variables
 * Return: NULL
 */
void print_environment(void)
{
	int i = 0;
	char *const *environ = get_environ();

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
 * get_environ - Gets the current environment variables.
 * Return: A pointer to the first element of the environ array.
 */
char **get_environ(void)
{
	extern char **environ;
	return environ;
}
