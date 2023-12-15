#ifndef MAIN_H
#define MAIN_H

#define PERROR(msg) perror(msg)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/**
 * main - main function
 * @ac: parameter 1
 * @argv: parameter 2
 * Return: void
 */

int main(int ac, char **argv);
void cmdexec(char **argv);
void print_environment(void);
char *find_location(char *command);
int stat(const char *pathname, struct stat *statbuf);
char *_getline();
char *enter(char *string);
void hashtag_handler(char *buff);

#endif /*MAIN_H*/
