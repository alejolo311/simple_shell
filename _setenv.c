#include "hsh.h"
/**
 * _setenv - function setenv
 * desc: set a enviroment variable
 * @argv: the parameters
 * @execnt: the counter
 * @lenv: the enviroment list
 * Return: 1 in success.
 */
int _setenv(char **argv, lenv_s **lenv, unsigned int *execnt)
{
	int i, asign = 0;
	char *variable, *value, *var;
	lenv_s *h;
	char *newvalue;
	char buffer[120];

	(void) execnt;
	h = *lenv;
	variable = argv[2];
	value = argv[3];
	if (variable && value)
	{
		for (i = 0; h; i++, h = h->next)
		{

			var = h->var;
			if (_strncmp(var, variable, _strlen(variable)) == 0)
			{

				free(h->var);
				sprintf(buffer, "%s=%s", variable, value);
				newvalue = _strdup(buffer);
				h->var = newvalue;
				asign = 1;
				break;
			}
		}
		if (asign == 0)
		{
			sprintf(buffer, "%s=%s", variable, value);
			add_node(lenv, buffer);
		}
	}
	else
		write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 29);

	return (1);
}
