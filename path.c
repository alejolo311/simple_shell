#include "hsh.h"

/**
 * path - Evaluate the name for execution taking into account PATH if necessary
 * @name: Name of the command to execute
 * @lenv: The environment list
 * Return: For succesful the full path other case NULL.
 */
char *path(char *name, lenv_s **lenv)
{
unsigned int i;
int j, k;
char *str1, *token, *tmp = NULL, **env = menv(lenv);
static char **paths, *pa;
printf("llego al path\n");
	if (_strncmp(name, "FLUSH", 5) == 0)
	{	free(pa), free(paths), free(env);
		return (NULL);
	}
	if (access(name, F_OK | R_OK | X_OK) == 0 &&
			(name[0] == '/' || name[0] == '.'))
	{	free(env);
		return (_strdup(name));
	}
	if (paths == NULL)
	{
		for (i = 0; env[i] != NULL; i++)
			if (_strncmp(env[i], "PATH", 4) == 0)
				break;
		if (env[i] == NULL)
		{	free(env);
			return (NULL);
		} tmp = _strdup(env[i]);
		for (k = 1, str1 = tmp; (token = strtok(str1, ":")); k++, str1 = NULL)
			if (token == NULL)
				break;
		free(tmp), pa = _strdup(env[i]), paths = malloc(k * sizeof(char **));
		for (j = 0, str1 = (pa + 5); ; j++, str1 = NULL)
		{	paths[j] = strtok(str1, ":");
			if (paths[j] == NULL)
				break;	}
	} for (k = 0; paths[k] != NULL; k++)
	{	tmp = malloc((_strlen(paths[k]) + _strlen(name) + 2) * sizeof(char));
		sprintf(tmp, "%s/%s", paths[k], name);
		if (access(tmp, F_OK | R_OK | X_OK) == 0)
		{	free(env);
			return (tmp);
		} free(tmp);
	} free(env);
	return (NULL);
}
