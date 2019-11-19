#include "hsh.h"

int check_builtin(char* builtin, char **env)
{

	if (strncmp(builtin, "exit", 4) == 0)
		return (-19);
	else if (strncmp(builtin, "cd", 2) == 0)
	{
		printf("cd\n");
		return (1);
	}
	else if (strncmp(builtin, "env", 3) == 0)
	{
		unsigned int i;
		for (i = 0; env[i] != NULL; i++)
		printf("%s\n", env[i]);
		return (1);
	}
	else
		return (0);
}
