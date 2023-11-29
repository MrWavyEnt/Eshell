#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - Entry point for the simple shell program.
 * Description:
 * This program implements a basic shell that reads a command from user,
 * tokenizes it, and allocates memory for the tokenized strings.
 * It provides a foundation for executing commands using execve.
 * Return: Always 0 on success.
 */
int main(void)
{
	char *cmp_com = NULL, *copy_com = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	char *token;
	const char *delim = " \n";
	char **argv;
	int i = 0;
	int num_tokens = 0;

	printf("$ ");

	nchars_read = getline(&cmp_com, &n, stdin)
		;
	copy_com = malloc(sizeof(char) * nchars_read);

	if (copy_com == NULL)
	{
		perror("tsh : memory allocation error");
		return (-1);
	}
	strcpy(copy_com, cmp_com);

	if (nchars_read == -1)
	{
		printf("Exiting shell....\n");
		return (-1);
	}
	else
		{

			token = strtok(cmp_com, delim);

			while
				(token != NULL)
	{
		num_tokens++;

		argv = malloc(sizeof(char *) * num_tokens);

		token = strtok(copy_com, delim);

		for (i = 0; token != NULL; i++)
		{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);

		token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		free(argv);
		free(cmp_com);
		free(copy_com);
	}
		}
	return (0);
}
