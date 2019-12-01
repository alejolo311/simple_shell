#include "hsh.h"
/**
 * _ex - function enviroment
 * desc: print the enviroment
 * @argv: the parameters
 * @lenv: the enviroment
 * @e: the command execution counter
 * Return: 1 in success.
 */
int _ex(char **argv, lenv_s **lenv, unsigned int *e)
{
	int ret = 0, pos = 2;
	char msg[80];

	(void) lenv;
	if (argv[pos] == NULL)
		return (0);
	if (_isdigit(argv[2]) == 1)
		ret = _atoi(argv[pos]);
	else
	{
		sprintf(msg, "%s: %d: %s: Illegal number: %s\n",
					argv[0], *e, argv[1], argv[2]);
		write(STDERR_FILENO, &msg, _strlen(msg));
		return (2);
	}
	if (ret < 0)
	{
		sprintf(msg, "%s: %d: %s: Illegal number: %d\n", argv[0], *e, argv[1], ret);
		write(STDERR_FILENO, &msg, _strlen(msg));
		ret = 2;
	}
	else if (ret > 255)
	{
		ret = ret % 256;
	}

	return (ret);
}
