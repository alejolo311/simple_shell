#include "hsh.h"
/**
 * check_builtin - check if the input is a built-in
 * desc: check if the command in the inpit is a valid built-in
 * @builtin: the command to check
 * Return: -19 in exit case, 1 in success, 0 in no exec
 */
int (*check_builtin(char *builtin))()
{
	int i; /* the counter to itarate the struct to search the correct builtin" */
	builtin_s built[] = {
		{"exit", _ex},
		{"env", _env},
		{"cd", _cd},
		{"help", _help},
		{"history", _history},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"hlphelp", _hlphelp},
		{"hlpcd", _hlpcd},
		{"hlpexit", _hlpexit},
		{"hlphistory", _hlphistory}
	};
	int built_len = sizeof(built) / sizeof(builtin_s);
	const char *p = builtin;

	if (p != NULL)
	{
		for (i = 0; i < built_len; i++)
		{
			if (strcmp(builtin, built[i].s) == 0)
				return (built[i].f);
		}
	}
	return (NULL);
}
