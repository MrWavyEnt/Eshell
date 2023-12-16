#include "main.h"

/**
 * main - The main function that includes all functions needed for the shell
 * @argv: argument vector
 * @ac: argument count
 * Return: 1
 */
int main(int ac, char **argv)
{
   char *prompt = "(simple_shell)$ ";
   char lineptr[256];
   char *lineptr_copy = NULL;
   const char *delim = " \n";
   int num_tokens = 0;
   char *token;
   int i;
   pid_t pid;
   int status;
   (void)ac;

   while (1)
   {
       printf("%s", prompt);
       if(fgets(lineptr, sizeof(lineptr), stdin) == NULL)
       {
           printf("Exiting shell....\n");
           return (-1);
       }

       if(strcmp(lineptr, "exit\n") == 0)
       {
           break;
       }

       lineptr_copy = malloc(sizeof(char) * strlen(lineptr));
       if (lineptr_copy == NULL)
       {
           perror("tsh: memory allocation error");
           return (-1);
       }
       strcpy(lineptr_copy, lineptr);
       token = strtok(lineptr, delim);
       while (token != NULL)
       {
           num_tokens++;
           token = strtok(NULL, delim);
       }
       num_tokens++;
       argv = malloc(sizeof(char *) * num_tokens);
       token = strtok(lineptr_copy, delim);
       for (i = 0; token != NULL; i++)
       {
           argv[i] = malloc(sizeof(char) * strlen(token));
           strcpy(argv[i], token);
           token = strtok(NULL, delim);
       }

       pid = fork();
      if (pid == -1) {
          perror("tsh: fork error");
	  return (-1);
      }

      if (pid == 0) {
          if (execvp(argv[0], argv) == -1) {
              perror("tsh");
              return (-1);
          }
      }
      else {
          waitpid(pid, &status, 0);
      }

   }
   free(lineptr_copy);
   return (0);
}
