#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void handle_setenv(char **argv)
{
  if (argv[1] == NULL || argv[2] == NULL)
  {
      fprintf(stderr, "Error: Missing arguments for setenv\n");
      return;
  }

  if (setenv(argv[1], argv[2], 1) == -1)
  {
      perror("Error:");
  }
}

void handle_unsetenv(char **argv)
{
  if (argv[1] == NULL)
  {
      fprintf(stderr, "Error: Missing argument for unsetenv\n");
      return;
  }

  if (unsetenv(argv[1]) == -1)
  {
      perror("Error:");
  }
}

