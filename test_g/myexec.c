#include "hsh.h"

/**
 * myexec - Exececutes a command
 * @argc: Quantity of parameters
 * @argv: The end NULL list of parameters
 * @env: The variables from the environment
 *
 * Return: Always 0
 */
int myexec(int argc, char **argv, char **env)
{
pid_t pid;
int status, ret;
char msg[80], *sentence;

	(void) argc;

	sentence = path(argv[1], env);
	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	else if (pid == 0)
	{
		ret = execve(sentence, (argv + 1), env);
		if (ret == -1)
		{
			sprintf(msg, "%s: 1: %s: not found\n", argv[0], argv[1]);
			write(STDERR_FILENO, &msg, strlen(msg));
			free(sentence);
			path("FLUSH", env);
			exit(1);
		}
	}
	else
		wait(&status);

	free(sentence);
	return (EXIT_SUCCESS);
}
