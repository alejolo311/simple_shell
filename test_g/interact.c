#include "hsh.h"

/**
 * interact - Exececutes a command
 *
 * Return: Always 0
 */
int interact(int ac, char **av, char **env)
{
char *line = NULL;
size_t len = 0;
int read = 1, j, argc, inter = 0;
char *str1, *token;
char *saveptr1;
char **argv;

	(void) ac;
	if (isatty(STDIN_FILENO) == 0)
		inter = 0;
	else
		inter = 1;

	if (inter == 1)
		printf("#cisfun$ ");

	read = getline(&line, &len, stdin);

	while (read)
	{
		for (argc = 1, str1 = line; ; argc++, str1 = NULL)
		{
			token = strtok_r(str1, " \t\n", &saveptr1);
			if (token == NULL)
				break;
		}
		argc++;

		argv = malloc((argc + 2) * sizeof(char **));
		if (argv == NULL)
		{
			free(line);
			perror("Error: ");
			return(-1);
		}

		argv[0] = av[0];
		for (j = 1, str1 = line; ; j++, str1 = NULL)
		{
			token = strtok_r(str1, " \t\n", &saveptr1);
			argv[j] = token;
			if (token == NULL)
				break;
		}

		if (myexec(argc, argv, env) != EXIT_SUCCESS)
		{
			free(line);
			perror("InterErr:");
			return(-1);
		}

		if (inter == 1)
			printf("#cisfun$ ");
		read = getline(&line, &len, stdin);
		if (strncmp(line, "exit", 4) == 0 || read == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
	}

	free(line);
	return (EXIT_SUCCESS);
}
