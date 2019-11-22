#include "hsh.h"
/**
 * _setenv - function setenv
 * desc: set a enviroment variable
 * @argv: the parameters
 * @execnt: the counter
 * @env: the enviroment
 * Return: 1 in success.
 */
int printvariable(char **argv, char **env, unsigned int *execnt)
{
int i;
char *var, *_value;

	(void) execnt;
  	var = argv[1] + 1;
  	if (var)
    	{
     		for(i = 0; env[i] != NULL; i++)
		{
			if (strncmp(env[i], var, strlen(var)) == 0)
			{
				break;
			}
		}
		_value = env[i] + (strlen(var) + 1);
		printf("%s", _value);
	}
	else
		write(STDERR_FILENO,"Usage:$VARIABLE\n", 15);

	return (1);

}

