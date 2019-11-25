#include "hsh.h"
/**
 * _setenv - function setenv
 * desc: set a enviroment variable
 * @argv: the parameters
 * @execnt: the counter
 * @env: the enviroment
 * Return: 1 in success.
 */
int _setenv(char **argv, lenv_s **lenv, unsigned int *execnt)
{

	int i, j;
	char *variable, *value, *_value, *var;
	(void) execnt;
	lenv_s *h = *lenv;
	char *newvalue;

  	variable = argv[2];
  	value = argv[3];
  	if (variable && value)
    	{
     		for(i = 0; h; i++, h = h->next)
		{
			var = h->var;
			if (strncmp(var, variable, strlen(variable)) == 0)
			{
				free(h->var);
				newvalue = strdup("sebas");
				h->var = newvalue;
				break;
			}
		}
	}
	else
		write(STDERR_FILENO,"Usage: setenv VARIABLE VALUE\n", 29);

	return (1);

}

