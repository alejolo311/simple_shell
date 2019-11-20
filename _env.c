#include "hsh.h" 
/**
 * _env - function enviroment
 * desc: print the enviroment
 * @argv: the parameters
 * @env: the enviroment
 * Return: 1 in success.
 */
int _env(char **argv, char **env, unsigned int *execnt)
{
	unsigned int i;

     	(void) argv;
	(void) env;
	(void) execnt;

     	for (i = 0; env[i] != NULL; i++)
      	printf("%s\n", env[i]);
     	return (1);
}
