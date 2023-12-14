#ifndef MAIN_H
#define MAIN_H

#define PERROR(msg) perror(msg)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int ac, char **argv);
void cmdexec(char **argv);
void print_environment(void);
char *find_location(const char *command);
int stat(const char *pathname, struct stat *statbuf);

#endif /*MAIN_H*/
