#include "hsh.h"
/**
 * check_variable - check if the input is a variable
 * desc: set a enviroment variable
 * @argv: the parameters
 * @lenv: the enviroment
 * Return: 1 in success.
 */
char **check_variable(char **argv, lenv_s **lenv)
{
	int i;

	(void) lenv;

	for (i = 0; argv[i] != NULL; i++)
	{

		if (argv[i][0] == '$' && argv[i][1] == '$')
		{
			printf("%d\n", getpid());
			break;
		}

	}

	return (argv);
}
