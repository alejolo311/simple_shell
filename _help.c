#include "hsh.h"

int prn_help(char *command);

/**
 * _help - function help
 * desc: print the help of the builtins
 * @av: the parameters
 * @env: the enviroment
 * @e: the counter
 * Return: EXIT_SUCCESS in success.
 */
int _help(char **av, char **env, unsigned int *e)
{
char msg[120];
int (*f)(), builtin;

	(void) env;
	if (av[2] == NULL)		/* When "help" */
	{
		prn_help(NULL);
		return (1);
	}

	if (av[2][0] == '-')
		sprintf(msg, "%s%s", "hlp", av[3]);	/* When "help [-sd] ..." */
	else
		sprintf(msg, "%s%s", "hlp", av[2]);	/* When "help help" */
	f = check_builtin(msg);
	if (f != NULL)		/* If there is function */
	{
		builtin = f(av, env, e);
		if (builtin != EXIT_SUCCESS)
		{
		sprintf(msg, "%s: %d: help: no help topics match '%s'. Try ",
				av[0], *e, (av[2][0] != '-') ? av[2] : av[3]);
		sprintf(msg, "%s'help help' or 'man -k %s' or 'info %s'.\n", msg,
				(av[2][0] != '-') ? av[2] : av[3], (av[2][0] != '-') ? av[2] : av[3]);
		write(STDERR_FILENO, msg, strlen(msg));
		return (-1);
		}
	}
	else				/* If there isn't function */
	{
		sprintf(msg, "%s: %d: help: no help topics match '%s'. Try ",
				av[0], *e, (av[2][0] != '-') ? av[2] : av[3]);
		sprintf(msg, "%s'help help' or 'man -k %s' or 'info %s'.\n", msg,
				(av[2][0] != '-') ? av[2] : av[3], (av[2][0] != '-') ? av[2] : av[3]);
		write(STDERR_FILENO, msg, strlen(msg));
		return (-1);
	}

	return (EXIT_SUCCESS);
}

/**
 * prn_help - Print the build
 * @command: the command to print
 * Return: -19 in exit case, 1 in success, 0 in no exec
 */
int prn_help(char *command)
{
int i; /* Line printing counter */
char *msg[] = {
"GNU hsh, version 1.0+ - release (x86_64-pc-linux-gnu)\n",
"These shell commands are defined internally.  Type 'help' to see this list.\n",
"Type 'help name' to find out more about the function 'name'.\n",
"Use 'info bash' to find out more about the shell in general.\n",
"Use 'man -k' or `info' to find out more about commands not in this list.\n",
"\n",
"A star (*) next to a name means that the command is disabled.\n",
"\n",
"cd [-L|[-P [-e]] [-@]] [dir]\n",
"exit [n]\n",
"help [-dms] [pattern ...]\n",
"history [-c] [-d offset] [n] or history ",
"-anrw [filename] or history -ps arg [arg...]\n",
"setenv VARIABLE VALUE\n",
"unsetenv VARIABLE\n",
NULL
};

	if (command == NULL)
		for (i = 0; msg[i] != NULL; i++)
			write(STDOUT_FILENO, msg[i], strlen(msg[i]));

	return (EXIT_SUCCESS);
}
