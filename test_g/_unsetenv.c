#include "hsh.h"
/**
 * _unsetenv - function unsetenv
 * desc: unset a enviroment variable
 * @argv: the parameters
 * @execnt: the counter.
 * @env: the enviroment
 * Return: 1 in success.
 */
int _unsetenv(char **argv, char **env, unsigned int *execnt)
{
	(void) argv;
	(void) env;
	(void) execnt;

	printf("unsetenv\n");
	return (1);
}
