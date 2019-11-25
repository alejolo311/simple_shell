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
	(void) argv;
	(void) execnt;
	print_list(lenv);
	return (1);
}
