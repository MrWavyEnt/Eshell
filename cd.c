#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void handle_cd(char **argv)
{
   char cwd[PATH_MAX];

   if (argv[1] == NULL)
   {
       char *home = getenv("HOME");
       if (home == NULL)
       {
           fprintf(stderr, "Error: HOME environment variable is not set\n");
           return;
       }
       if (chdir(home) == -1)
       {
           perror("Error:");
       }
   }
   else if (strcmp(argv[1], "-") == 0)
   {
       char *oldpwd = getenv("OLDPWD");
       if (oldpwd == NULL)
       {
           fprintf(stderr, "Error: OLDPWD environment variable is not set\n");
           return;
       }
       if (chdir(oldpwd) == -1)
       {
           perror("Error:");
       }
   }
   else
   {
       if (chdir(argv[1]) == -1)
       {
           perror("Error:");
       }
   }

   if (getcwd(cwd, sizeof(cwd)) != NULL)
   {
       setenv("PWD", cwd, 1);
   }
   else
   {
       perror("Error:");
   }
}

