#include "hsh.h"

/**
 * myexec - Exececutes a command
 * @argc: Quantity of parameters
 * @argv: The end NULL list of parameters
 *
 * Return: Always 0
 */
int myexec(int argc, char **argv, char **env)
{
pid_t pid;
int status;

	(void) argc;

	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			perror("Error:");
		}
	}
	else
		wait(&status);

	return (0);
}
