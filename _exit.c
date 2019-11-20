#include "hsh.h"
/**
 * _ex - function enviroment
 * desc: print the enviroment
 * @argv: the parameters
 * @env: the enviroment
 * @e: the command execution counter
 * Return: 1 in success.
 */
int _ex(char **argv, char **env, unsigned int *e)
{
	int ret = 0;
	char msg[80];
	(void) env;

	if (argv[2] == NULL)
		return (0);
	ret = atoi(argv[2]);
	if (ret < 0)
	{
		sprintf(msg, "%s: %d: %s: Illegal Number: %d\n", argv[0], *e, argv[1], ret);
		write(STDERR_FILENO, &msg, strlen(msg));
	}

	return (ret);
}
