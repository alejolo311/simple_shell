#include "hsh.h"
/**
 * _unsetenv - function setenv
 * desc: set a enviroment variable
 * @argv: the parameters
 * @execnt: the counter
 * @env: the enviroment
 * Return: 1 in success.
 */
int _unsetenv(char **argv, char **env, unsigned int *execnt)
{
int i;
unsigned int j;
char *var, *_var;

	(void) execnt;
  	var = argv[2];
  	if (var)
    	{
     		for(i = 0; env[i] != NULL; i++)
		{
			if (strncmp(env[i], var, strlen(var)) == 0)
			{
				break;
			}
		}
		for(j = 0; j <= strlen(env[i]); j++)
			_var = env[i] + 0;
			_var[0] = '\0';
	}
	else
		write(STDERR_FILENO,"Usage: unsetenv VARIABLE VALUE\n", 31);

	return (1);

}

