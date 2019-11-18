#include "hsh.h"

/**
 * interact - Exececutes a command
 * @av: Parameters for the program
 * @env: The variables from the environment
 *
 * Return: Always 0
 */
int interact(char **av, char **env)
{
size_t len = 0;
int read = 1, j, argc, inter = 1;
char *str1, *token, **argv, *line = NULL, *tmp = NULL;

	isatty(STDIN_FILENO) == 0 ? inter = 0 : inter;
	do {
		inter == 1 ?  printf("#cisfun$ ") : inter;
		read = getline(&line, &len, stdin);
		if (strncmp(line, "exit", 4) == 0 || read == -1)
		{
			read == -1 && inter == 1 ? printf("\n") : read;
			free(line), exit(EXIT_SUCCESS);
		}
		tmp = strdup(line);
		for (argc = 1, str1 = tmp; ; argc++, str1 = NULL)
		{
			token = strtok(str1, " \t\n");
			if (token == NULL)
				break;
		}
		argc++;
		argv = malloc((argc + 2) * sizeof(char **));
		if (argv == NULL)
		{
			free(line), perror("Error: ");
			return (-1);
		}
		argv[0] = av[0];
		for (j = 1, str1 = line; ; j++, str1 = NULL)
		{
			token = strtok(str1, " \t\n"), argv[j] = token;
			if (token == NULL)
				break;
		}
		if (argc > 2)
			myexec(j, argv, env);
		free(argv), free(tmp);
	} while (read);
	free(line);
	return (EXIT_SUCCESS);
}
