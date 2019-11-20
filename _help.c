#include "hsh.h"
/**
 * _help - function help
 * desc: print the help of the builtins
 * @argv: the parameters
 * @execnt: the counter
 * @env: the enviroment
 * Return: 1 in success.
 */
int _help(char **argv, char **env, unsigned int *execnt)
{
	(void) argv;
	(void) env;
	(void) execnt;

	printf("help\n");
	return (1);
}
