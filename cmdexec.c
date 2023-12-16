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
       exit(status);
}

/**
 * cmdexec - Executes a command specified by the argv array
 * using the execve system call.
 * @argv: Array of strings representing the command and it's arguments
 * Return: Does not return on success. Exits the process if an error occurs.
 */
void cmdexec(char **argv)
{
       char *command = NULL, *actual_command = NULL;
       int i;

       if (argv)
       {
               command = argv[0];

               printf("Command: %s\n", command);
               for (i = 1; argv[i] != NULL; i++)
               {
                      printf("Argument %d: %s\n", i, argv[i]);
               }

               if (strcmp(command, "exit") == 0)
               {
                      handle_exit(0);
               }
               else if (strcmp(command, "env") == 0)
               {
                      print_environment();
               }
               else if (strcmp(command, "/bin/ls") == 0)
               {
                      char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
                      printf("Before execve\n");
                      if (execve(argv[0], argv, NULL) == -1)
                      {
                              perror("Error:");
                      }
                      printf("After execve\n");
               }
               else
               {
                      actual_command = find_location(command);

                      if (actual_command == NULL)
                      {
                              printf("Command not found\n");
                              return;
                      }

                      if (execve(actual_command, argv, NULL) == -1)
                      {
                              PERROR("Error:");
                              return;
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

