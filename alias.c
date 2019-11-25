#include "hsh.h"
/**
 * alias - function setenv
 * desc: set a enviroment variable
 * @argv: the parameters
 * @execnt: the counter
 * @lenv: the enviroment list
 * Return: 1 in success.
 */
int alias(char **argv, lenv_s **lenv, unsigned int *execnt)
{
	(void) argv;
	(void) lenv;
	(void) execnt;
	printf("alias\n");
	return (1);
}

