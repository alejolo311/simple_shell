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
int i;
unsigned int j;
char *var, *value, *_value;

	(void) execnt;
  	var = argv[2];
  	value = argv[3];
  	if (var && value)
    	{
     		for(i = 0; env[i] != NULL; i++)
		{
			if (strncmp(env[i], var, strlen(var)) == 0)
			{
				break;
			}
		}
		_value = env[i] + (strlen(var) + 1);

		for (j = 0; j < strlen(value); j++)
		{
			_value[j] = value[j];
		}
		_value[j] = '\0';
	}
	else
		write(STDERR_FILENO,"Usage: setenv VARIABLE VALUE\n", 29);

	return (1);

}

