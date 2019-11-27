#include "hsh.h"

int prn_hlphelp(void);

/**
 * _hlphelp - function help
 * desc: print the help of the builtins
 * @av: the parameters
 * @lenv: the enviroment list
 * @e: the counter
 * Return: EXITSUCCESS in success.
 */
int _hlphelp(char **av, lenv_s **lenv, unsigned int *e)
{
char msg[120];

	(void) lenv;
	(void) e;
	if (_strcmp(av[2], "-d") == 0)
	{
		sprintf(msg, "help: Display information about builtin commands.\n");
		write(STDOUT_FILENO, msg, strlen(msg));
	}
	else if (_strcmp(av[2], "-s") == 0)
	{
		sprintf(msg, "help: help [-dms] [pattern ...]\n");
		write(STDOUT_FILENO, msg, strlen(msg));
	}
	else
		prn_hlphelp();

	return (EXIT_SUCCESS);
}

/**
 * prn_hlphelp - Print the build
 * Return: -19 in exit case, 1 in success, 0 in no exec
 */
int prn_hlphelp(void)
{
int i; /* Line printing counter */
char *msg[] = {
"help: help [-dms] [pattern ...]\n",
"    Display information about builtin commands.\n",
"\n",
"    Displays brief summaries of builtin commands.  If PATTERN is\n",
"    specified, gives detailed help on all commands matching PATTERN,\n",
"    otherwise the list of help topics is printed.\n",
"\n",
"    Options:\n",
"      -d        output short description for each topic\n",
"      -m        display usage in pseudo-manpage format\n",
"      -s        output only a short usage synopsis for each topic matching\n",
"        PATTERN\n",
"\n",
"    Arguments:\n",
"      PATTERN   Pattern specifiying a help topic\n",
"\n",
"    Exit Status:\n",
"    Returns success unless PATTERN is not found or an invalid option is given.\n",
NULL
};

	for (i = 0; msg[i] != NULL; i++)
		write(STDOUT_FILENO, msg[i], strlen(msg[i]));

	return (EXIT_SUCCESS);
}
