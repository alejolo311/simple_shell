#include "hsh.h"

int prn_hlpexit(void);

/**
 * _hlpexit - function help
 * desc: print the help of the builtins
 * @av: the parameters
 * @env: the enviroment
 * @e: the counter
 * Return: EXIT_SUCCESS in success.
 */
int _hlpexit(char **av, char **env, unsigned int *e)
{
char msg[120];

	(void) env;
	(void) e;
	if (strcmp(av[2], "-d") == 0)
	{
		sprintf(msg, "exit - Exit the shell.\n");
		write(STDOUT_FILENO, msg, strlen(msg));
	}
	else if (strcmp(av[2], "-s") == 0)
	{
		sprintf(msg, "exit: exit [n]\n");
		write(STDOUT_FILENO, msg, strlen(msg));
	}
	else
		prn_hlpexit();

	return (EXIT_SUCCESS);
}

/**
 * prn_hlpexit - Print the build
 * Return: -19 in exit case, 1 in success, 0 in no exec
 */
int prn_hlpexit(void)
{
int i; /* Line printing counter */
char *msg[] = {
"exit: exit [n]\n",
"    Exit the shell.\n",
"\n",
"    Exits the shell with a status of N.  If N is omitted, the exit status\n",
"    is that of the last command executed.\n",
NULL
};

	for (i = 0; msg[i] != NULL; i++)
		write(STDOUT_FILENO, msg[i], strlen(msg[i]));

	return (EXIT_SUCCESS);
}
