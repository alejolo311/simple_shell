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
	int status, ret = 0, es; /* ret = return, es = exit status */
	char msg[80], *sentence = NULL;
	char **env = menv(lenv);

	(void) argc;
	sentence = path(argv[1], lenv);
	if (sentence == NULL)
	{
		sprintf(msg, "%s: %d: %s: not found\n", argv[0], *execnt, argv[1]);
		write(STDERR_FILENO, &msg, strlen(msg));
		free(env);
		return (EXIT_SUCCESS);
	}
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
			free(sentence), free(env);
			exit (127);
		}
	}
	else
	{

		wait(&status);
		if ( WIFEXITED(status))
		{
			es = WEXITSTATUS(status);
			(void) es;
		}
	}
	free(sentence), free(env);
	return (EXIT_SUCCESS);
}
