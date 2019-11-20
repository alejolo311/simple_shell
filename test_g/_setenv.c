#include "hsh.h"
/**
 * _setenv - function setenv
 * desc: set a enviroment variable
 * @argv: the parameters
 * @execnt: the counter
 * @env: the enviroment
 * Return: 1 in success.
 */
int _setenv(char **argv, char **env, unsigned int *execnt)
{
	(void) argv;
	(void) env;
	(void) execnt;

	printf("setenv\n");
	return (1);
}
