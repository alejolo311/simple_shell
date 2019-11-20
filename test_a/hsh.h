#ifndef H_SHELL
#define H_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <signal.h>


/**
 * struct builtin - Structure for builtins
 * @s: String to compare
 * @f: Function to execute
 */
typedef struct builtin
{
	char *s;
	int (*f)();
} builtin_s;

int myexec(int argc, char **argv, char **env, unsigned int *execnt);
int interact(char **argv, char **env, unsigned int *execnt);
void handsigint(int sign);
char *path(char *name, char **env);

/* Function related with Built-ins */
int (*check_builtin(char *line))();
int _env(char **argv, char **env, unsigned int *execnt);
int _ex(char **argv, char **env, unsigned int *execnt);
int _cd(char **argv, char **env, unsigned int *execnt);
int _setenv(char **argv, char **env, unsigned int *execnt);
int _unsetenv(char **argv, char **env, unsigned int *execnt);
int _history(char **argv, char **env, unsigned int *execnt);
int _help(char **argv, char **env, unsigned int *execnt);
#endif /* H_SHELL */
