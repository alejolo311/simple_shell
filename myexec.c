#include "hsh.h"

/**
 * myexec - Exececutes a command
 * @argc: Quantity of parameters
 * @argv: The end NULL list of parameters
 *
 * Return: Always 0
 */
int myexec(int argc, char **argv)
{
	(void) argc;
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error:");
	}
	return (0);
}
