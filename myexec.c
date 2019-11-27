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
	int status, ret = 0, es, isnull = 0; /* ret = return, es = exit status */
	char msg[80], *sentence = NULL, *pathos, *tmp = NULL, **env = menv(lenv);
	struct stat st;

	st.st_mode = 0, (void) argc, pathos = _getenv("PATH", lenv);
	if (_strncmp(pathos, ":", 1) == 0)
	{	tmp = _strdup(argv[1]), sentence = tmp;
		if (access(sentence, F_OK | R_OK | X_OK) == -1)
			free(tmp), sentence = NULL;
	}
	else
		sentence = path(argv[1], lenv);
	sentence != NULL ? stat(sentence, &st) : (isnull = 1);
	if (((st.st_mode & S_IFMT) == S_IFDIR) && isnull == 0)
	{
		sprintf(msg, "%s: %d: %s: Permission denied\n", argv[0], *execnt, argv[1]);
		write(STDERR_FILENO, &msg, _strlen(msg)), free(env), free(sentence);
		return (126);
	}
	if (sentence == NULL)
	{	sprintf(msg, "%s: %d: %s: not found\n", argv[0], *execnt, argv[1]);
		write(STDERR_FILENO, &msg, _strlen(msg));
		free(env);
		return (127);
	} pid = fork();
	if (pid == -1)
	{	perror("Error:");
		return (1);
	}
	else if (pid == 0)
	{	ret = execve(sentence, (argv + 1), env);
		if (ret == -1)
			exit(127);
	} else
	{	wait(&status);
		if (WIFEXITED(status))
			es = WEXITSTATUS(status);
	} free(sentence), free(env);
	return (es);
}
