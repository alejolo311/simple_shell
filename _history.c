#include "hsh.h" 
/**
 * _history - function history
 * desc: print the history of commands
 * @argv: the parameters
 * @env: the enviroment
 * Return: 1 in success.
 */
int _history(char **argv, char **env, unsigned int *execnt)
{
     	(void) argv;
	(void) env;
	(void) execnt;

      	printf("history\n");
	return (1);
}
