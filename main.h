#ifndef MAIN_H
#define MAIN_H

/* Standard Libraries*/
#define PERROR(msg) perror(msg)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <linux/limits.h>

/* External Environment*/
extern char **environ;

/* Function Prototypes */


/* handles */
int _putchar(char i);
void _puts(char *string);
char *_strncpy(char *destint, char *srcstr, int c);
int _strlen(char *sin);
int _atoi(char *ai);
char *_strdup(char *string);
int _strncmp(const char *strg1, const char *strg2, size_t nchr);
char *_strchr(char *sin, char chr);
char *_strcat(char *destint, char *srcstr);
char *_strcpy(char *destint, char *srcstr);
int _strcmp(char *strg1, char *strg2);
int _isalpha(int isa);
char *_itoa(unsigned int ia);
void array_rev(char *ary, int lent);
int intlen(int lentnum);


/* Getline function */
char *shell_getline();
char *enter(char *string);
char *space(char *str);
void hashtag_handler(char *buff);

/* String Token Functions */
unsigned int delim_chk(char c, const char *delstr);
char *_strtok(char *str, const char *delimit);

/* Builtin Commands Functions*/
int change_dir(char **bltcmd, __attribute__((unused))int statl);
int dis_env(__attribute__((unused)) char **bltcmd, __attribute__((unused)) int statl);
int echo_bul(char **bltcmd, int statl);
int history_dis(__attribute__((unused))char **c, __attribute__((unused))int statl);
int check_builtin(char **bltcmd);
int handle_builtin(char **bltcmd, int statl);
void exit_bul(char **bltcmd, char *in_u, char **argv, int c, int e_state);
char **shell_parsecmd(char *ustring);
void read_file(char *fcomm, char **argv);
void treat_file(char *line, int ct, FILE *filme, char **argv);
void exit_bul_for_file(char **bltcmd, char *line, FILE *finme);


/* Error Handles */
void print_error(char *in_u, int cntsh, char **argv);
void _prerror(char **argv, int ercount, char **bltcmd);
void error_file(char **argv, int ercount);

/* Memeory Functions */
void *_realloc(void *pt, unsigned int old_s, unsigned int new_s);
void free_all(char **bltcmd, char *charpt);
char *_memcpy(char *destint, char *srcptr, unsigned int n);
void *fill_an_array(void *vpt, int el, unsigned int inlen);
void *_calloc(unsigned int s);

/* General Functions */
void envi_val(char **enviromt);
void free_env(char **env);
int path_find(char **bltcmd);
char *build(char *tkn, char *num);
char *_getenv(char *envinm);
void print_number(unsigned int unint);
void print_number_int(int nin);
int print_echo(char **bltcmd);
void prompt(void);
char **sept(char *in_s);
int check_cmd(char **bktcmd, char *in_u, int shexc, char **argv);
void signal_to_handle(int signil);
void PRINT(const char *str);
int history(char *in_u);

#endif /*MAIN_H*/
