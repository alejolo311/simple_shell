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

#define HISTORY_FILE ".simple_shell_history"

/**
 * struct commhist - Structure for the command history
 * @id: Id for the node
 * @cmd: The command
 * @next: The next node
 */
typedef struct commhist
{
	int id;
	char *cmd;
	struct commhist *next;
} commhist_s;

/**
 * struct lenv_s - singly linked list
 * @str: variable
 * @next: points to the next node
 * @var: enviroment variables.
 * Description: singly linked list node to store the env
 */
typedef struct lenv_s
{
	char *var;
	struct lenv_s *next;
} lenv_s;

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

int myexec(int argc, char **argv, lenv_s **env, unsigned int *execnt);
int interact(char **argv, lenv_s **env, unsigned int *execnt);
void handsigint(int sign);
char *path(char *name, lenv_s **env);
int currhist(commhist_s **h, commhist_s **t);
int addhist(char **argv);
int savehist(void);
int loadhist(void);

/* Function related with Built-ins */
int (*check_builtin(char *line))();
int _env(char **argv, lenv_s **lenv, unsigned int *execnt);
int _ex(char **argv, lenv_s **lenv, unsigned int *execnt);
int _cd(char **argv, lenv_s **lenv, unsigned int *execnt);
int _setenv(char **argv, lenv_s **lenv, unsigned int *execnt);
int _unsetenv(char **argv, lenv_s **lenv, unsigned int *execnt);
int _history(char **argv, lenv_s **lenv, unsigned int *execnt);
int _help(char **argv, lenv_s **lenv, unsigned int *execnt);
int _hlphelp(char **av, lenv_s **lenv, unsigned int *e);
int _hlpcd(char **av, lenv_s **lenv, unsigned int *e);
int _hlpexit(char **av, lenv_s **lenv, unsigned int *e);
int _hlphistory(char **av, lenv_s **lenv, unsigned int *e);


/* strings functions */

int _strlen(char *s);

/* enviroment funcs */
size_t print_list(lenv_s **head);
int delete_node(lenv_s **head, unsigned int index);
char **menv(lenv_s **head);
lenv_s *add_node(lenv_s **head, char *str);
lenv_s *cenv(char **env);
void free_list(lenv_s **head);
#endif /* H_SHELL */
