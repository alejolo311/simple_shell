#include "hsh.h"

void getverenv(char **home, char **env, char *var);
int askcwd(char **path, unsigned int size);
void prnerr(char *prg, unsigned int *e, char *path);

/**
 * _cd - function cd
 * desc: change between directories
 * @argv: the parameters
 * @e : the executions counter
 * @env: the enviroment
 * Return: EXIT_SUCCESS in success.
 */
int _cd(char **argv, char **env, unsigned int *e)
{
char ynprn = 0, *home = NULL, *pwd = NULL, *prev = NULL, *new = NULL;
unsigned int size = 512;

	getverenv(&home, env, "HOME");			/* Get home from environment */
	getverenv(&pwd, env, "OLDPWD");			/* Get oldpwd from environment */
	if (askcwd(&prev, size) == -1)			/* Get previous path, if fail resize */
	{
		free(home), free(pwd);
		return (-1);
	}
	if (argv[2] == NULL && home != NULL)	/* When "cd" (only) */
	{
		if (chdir(home) == -1)
		{
			prnerr(argv[0], e, home), free(home), free(pwd), free(prev);
			return (-1);
		}
	}
	else if (argv[2][0] == '~')				/* When "cd ~" */
	{
		if (chdir(home) == -1)
		{
			prnerr(argv[0], e, home), free(home), free(pwd), free(prev);
			return (-1);
		}
	}
	else if (argv[2][0] == '-')				/* When "cd -" */
	{
		if (chdir(pwd) == -1)
		{
			prnerr(argv[0], e, pwd), free(home), free(pwd), free(prev);
			return (-1);
		}
		ynprn = 1;
	}
	else
	{
		if (chdir(argv[2]) == -1)			/* When "cd path" */
		{
			prnerr(argv[0], e, argv[2]), free(home), free(pwd), free(prev);
			return (-1);
		}
	}
	if (askcwd(&new, size) == -1)			/* Get new path, if fail resize */
	{
		free(home), free(pwd), free(prev);
		return (-1);
	}
	setenv("OLDPWD", prev, 1);				/* Set the new path in environment */
	setenv("PWD", new, 1);
	if (ynprn)								/* Print the new path when necessary */
		write(STDOUT_FILENO, new, strlen(new)), write(STDOUT_FILENO, "\n", 1);
	free(home), free(pwd), free(prev), free(new);

	return (EXIT_SUCCESS);
}

/**
 * getverenv - Get the content from an environment variable
 * @home: the variable to store de value
 * @env: the enviroment
 * @var: the variable to find
 * Return: Nothing.
 */
void getverenv(char **home, char **env, char *var)
{
	while (*env != NULL)
	{
		if (strncmp(*env, var, strlen(var)) == 0)
		{
			*home = strdup((*env) + strlen(var) + 1);
			break;
		}
		env++;
	}
}

/**
 * askcwd - Get the current path
 * @path: the variable to store de value
 * @size: the lenght of bytes for the variable
 * Return: EXIT_SUCCESS when success, -1 if fails.
 */
int askcwd(char **path, unsigned int size)
{
	if (*path != NULL)
		free(path);
	*path = malloc(size);
	if (*path == NULL)
		return (-1);
	while (getcwd(*path, size) == NULL)		/* If fail to store */
	{
		size += 64;							/* Expands the size of buff */
		free(path);
		*path = malloc(size);				/* Try to get the memory from heap */
		if (*path == NULL)
			return (-1);
	}
	return (EXIT_SUCCESS);
}

/**
 * prnerr - Prints the errors on stdout
 * @prg: the name of shell
 * @e: the execution counter
 * @path: the path that fails
 * Return: Nothing.
 */
void prnerr(char *prg, unsigned int *e, char *path)
{
char msg[80];

	sprintf(msg, "%s: %d: cd: can't cd to %s\n", prg, *e, path);
	write(STDERR_FILENO, msg, strlen(msg));
}
