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

int myexec(int argc, char **argv, char **env, unsigned int *execnt);
int interact(char **argv, char **env, unsigned int *execnt);
void handsigint(int sign);
char *path(char *name, char **env);

#endif /* H_SHELL */
