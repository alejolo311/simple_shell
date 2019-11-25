#include "hsh.h"

/**
 * myexec - Exececutes a command
 * @argc: Quantity of parameters
 * @argv: The end NULL list of parameters
 * @lenv: The variables from the environment list
 * @execnt: the counter
 * Return: Always 0
 */
int myexec(int argc, char **argv, lenv_s **lenv, unsigned int *execnt)
{
pid_t pid;
int status, ret;
char msg[80], *sentence;
char **env = menv(lenv);

	(void) argc;

	sentence = path(argv[1], lenv);
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
			sprintf(msg, "%s: %d: %s: not found\n", argv[0], *execnt, argv[1]);
			write(STDERR_FILENO, &msg, strlen(msg));
			free(sentence);
			path("FLUSH", lenv);
			exit(1);
		}
	}
	else
		wait(&status);

	free(sentence), free(env);
	return (EXIT_SUCCESS);
}
