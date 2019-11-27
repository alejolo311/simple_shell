#include "hsh.h"
/**
 * _env - function enviroment
 * desc: print the enviroment
 * @argv: the parameters
 * @lenv: the enviroment list
 * @execnt: the counter
 * Return: 1 in success.
 */
int _env(char **argv, lenv_s **lenv, unsigned int *execnt)
{
	int i, len;

	(void) argv;
	(void) execnt;
	(void) lenv;
	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (EXIT_SUCCESS);
}
