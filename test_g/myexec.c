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
int status, ret;
char msg[80];

	(void) argc;

	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	else if (pid == 0)
	{
		if ((ret = execve(argv[1], (argv + 1), env)) == -1)
		{
			sprintf(msg, "%s: 1: %s: not found\n", argv[0], argv[1]);
			write(STDERR_FILENO, &msg, strlen(msg));
		}
	}
	else
		wait(&status);

	return (EXIT_SUCCESS);
}
