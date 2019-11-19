#include "hsh.h"

/**
 * path - Evaluate the name for execution taking into account PATH if necessary.
 * @name: Name of the command to execute
 * @env: The environment
 *
 * Return: For succesful the full path other case NULL.
 */
char *path(char *name, char **env)
{
unsigned int i;
int j, k;
char *str1, *token, *tmp;
static char **paths = NULL;

	if (strncmp(name, "FLUSH", 5) == 0)
	{
		free(paths);
		return(NULL);
	}
	if (access(name, F_OK | R_OK | X_OK) == 0)
		return (strdup(name));
	if (paths == NULL)
	{
    	i = 0;
    	while (env[i] != NULL)
    	{
			if (strncmp(env[i], "PATH", 4) == 0)
				break;
        	i++;
    	}
		tmp = strdup(env[i]);
		for (k = 1, str1 = tmp; ; k++, str1 = NULL)
		{
			token = strtok(str1, ":");
			if (token == NULL)
				break;
		}
		free(tmp);
		paths = malloc(k * sizeof(char **));
		for (j = 0, str1 = (*(env + i) + 5); ; j++, str1 = NULL)
		{
			paths[j] = strtok(str1, ":");
			if (paths[j] == NULL)
				break;
		}
	}
	k = 0;
	while (paths[k] != NULL)
	{
		tmp = malloc((strlen(paths[k]) + strlen(name) + 2) * sizeof(char));
		sprintf(tmp, "%s/%s", paths[k], name);
		if (access(tmp, F_OK | R_OK | X_OK) == 0)
			return(tmp);
		free(tmp);
		k++;
	}

	return (NULL);
}
