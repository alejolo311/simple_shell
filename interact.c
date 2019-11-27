#include "hsh.h"

char **askmem(int argc, char *line);

/**
 * interact - Exececutes a command
 * @av: Parameters for the program
 * @lenv: The variables from the environment list
 * @execnt: the counter
 * Return: Always 0
 */
int interact(char **av, lenv_s **lenv, unsigned int *execnt)
{
size_t len = 0;
int read = 1, j, argc = 0, inter = 1, (*f)() = NULL, builtin, ret = 0;
char *str1, *t, **argv, *line = NULL, *tmp = NULL, *myline = NULL;

	isatty(STDIN_FILENO) == 0 ? inter = 0 : inter;
	do {	inter == 1 ?  write(STDOUT_FILENO, "($) ", 4) : inter;
		fflush(stdin);
		read = getline(&line, &len, stdin);
		if (read == -1)
		{	read == -1 && inter == 1 ? write(1, "\n", 1) : read;
			free(line);
			return (EXIT_SUCCESS);
		}
		myline = _strdup(line);
		tmp = _strdup(myline);
		for (argc = 1, str1 = tmp; (t = strtok(str1, " \t\n")); argc++, str1 = NULL)
			if (t == NULL)
				break;
		argv = askmem(++argc + 2, myline);
		if (argv == NULL)
			return (-1);
		argv[0] = av[0];
		for (j = 1, str1 = myline; ; j++, str1 = NULL)
		{	t = strtok(str1, " \t\n"), argv[j] = t;
			if (t == NULL)
				break;
		}
		f = check_builtin(myline);
		if (f != NULL)
		{	builtin = f(argv, lenv, execnt);
			if (_strncmp(myline, "exit", 4) == 0 && builtin >= 0)
			{	free(argv), free(tmp), free(myline), free(line);
				return (builtin);
			}
		}
		else
			argc > 2 ? ret = myexec(j, argv, lenv, execnt) : argc;
		addhist(argv), free(argv), free(tmp), free(myline), (*execnt)++;
		if (ret == 127 && inter == 0)
		{	free(line);
			return (127);
		}
	} while (1);
	free(myline), free(line);
	return (ret);
}

/**
 * askmem - Allocates memory
 * @argc: Amount of memory to allocate
 * @myline: The pointer to line readed
 * Return: A pointer to the new memory area or NULL
 */
char **askmem(int argc, char *myline)
{
char **argv;

	argv = malloc((argc) * sizeof(char **));
	if (argv == NULL)
	{
		free(myline);
		perror("Error: ");
		return (NULL);
	}
	return (argv);
}
