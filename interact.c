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
int read = 1, j, argc, inter = 1, (*f)(), builtin;
char *str1, *t, **argv, *line = NULL, *tmp = NULL;

	isatty(STDIN_FILENO) == 0 ? inter = 0 : inter;
	do {
		inter == 1 ?  printf("#cisfun$ ") : inter;
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			read == -1 && inter == 1 ? write(1, "\n", 1) : read;
			free(line);
			return (EXIT_SUCCESS);
		}
		tmp = strdup(line);
		for (argc = 1, str1 = tmp; (t = strtok(str1, " \t\n")); argc++, str1 = NULL)
			if (t == NULL)
				break;
		argv = askmem(++argc + 2, line);
		if (argv == NULL)
			return (-1);
		argv[0] = av[0];
		for (j = 1, str1 = line; ; j++, str1 = NULL)
		{
			t = strtok(str1, " \t\n"), argv[j] = t;
			if (t == NULL)
				break;
		}
		f = check_builtin(line);
		if (f != NULL)
		{
			builtin = f(argv, lenv, execnt);
			if (strncmp(line, "exit", 4) == 0 && builtin >= 0)
			{
				free(argv), free(tmp), free(line);
				return (builtin);
			}
		}
		else
			argc > 2 ? myexec(j, argv, lenv, execnt) : argc;
		free(argv), free(tmp), (*execnt)++, addhist(argv);
	} while (read);
	free(line);
	return (EXIT_SUCCESS);
}

/**
 * askmem - Allocates memory
 * @argc: Amount of memory to allocate
 * @line: The pointer to line readed
 * Return: A pointer to the new memory area or NULL
 */
char **askmem(int argc, char *line)
{
char **argv;

	argv = malloc((argc) * sizeof(char **));
	if (argv == NULL)
	{
		free(line);
		perror("Error: ");
		return (NULL);
	}
	return (argv);
}
