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
char *str1, *token, *tmp, **env = menv(lenv);
static char **paths, *pa;

	if (strncmp(name, "FLUSH", 5) == 0)
	{
		free(pa), free(paths), free(env);
		return (NULL);
	}
	if (access(name, F_OK | R_OK | X_OK) == 0)
		return (strdup(name));
	if (paths == NULL)
	{
		for (i = 0; env[i] != NULL; i++)
			if (strncmp(env[i], "PATH", 4) == 0)
				break;
		tmp = strdup(env[i]);
		for (k = 1, str1 = tmp; (token = strtok(str1, ":")); k++, str1 = NULL)
			if (token == NULL)
				break;
		free(tmp), pa = strdup(env[i]);
		paths = malloc(k * sizeof(char **));
		for (j = 0, str1 = (pa + 5); ; j++, str1 = NULL)
		{
			paths[j] = strtok(str1, ":");
			if (paths[j] == NULL)
				break;
		}
	}
	for (k = 0; paths[k] != NULL; k++)
	{
		tmp = malloc((strlen(paths[k]) + strlen(name) + 2) * sizeof(char));
		sprintf(tmp, "%s/%s", paths[k], name);
		if (access(tmp, F_OK | R_OK | X_OK) == 0)
			return (tmp);
		free(tmp);
	}

	return (NULL);
}
