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

int myexec(int argc, char **argv, char **env);
int interac(char **env);

#endif /* H_SHELL */
