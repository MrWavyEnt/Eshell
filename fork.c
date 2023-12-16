#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * print_fork - fork creates a new child process, 
 * almost identical to the parent.
 *
 * Return: Always 0.
 */
int print_fork(void)
{
    pid_t my_pid;
    pid_t pid;

    printf("Before fork\n");
    pid = fork();
    if (pid == -1)
    {
        perror("Error:");
        return (1);
    }
    printf("After fork\n");
    my_pid = getpid();
    printf("My pid is %u\n", my_pid);
    return (0);
}
