#ifndef MAIN_H
#define MAIN_H

#define PERROR(msg) perror(msg)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int ac, char **argv);
void cmdexec(char **argv);
#endif /*MAIN_H*/
