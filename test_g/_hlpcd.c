#include "hsh.h"

int prn_hlpcd(void);

/**
 * _hlpcd - function help
 * desc: print the help of the builtins
 * @av: the parameters
 * @env: the enviroment
 * @e: the counter
 * Return: EXIT_SUCCESS in success.
 */
int _hlpcd(char **av, lenv_s **lenv, unsigned int *e)
{
char msg[120];

	(void) lenv;
	(void) e;
	if (strcmp(av[2], "-d") == 0)
	{
		sprintf(msg, "cd - Change the shell working directory.\n");
		write(STDOUT_FILENO, msg, strlen(msg));
	}
	else if (strcmp(av[2], "-s") == 0)
	{
		sprintf(msg, "cd: cd [-L|[-P [-e]] [-@]] [dir]\n");
		write(STDOUT_FILENO, msg, strlen(msg));
	}
	else
		prn_hlpcd();

	return (EXIT_SUCCESS);
}

/**
 * prn_hlpcd - Print the build
 * Return: -19 in exit case, 1 in success, 0 in no exec
 */
int prn_hlpcd(void)
{
int i; /* Line printing counter */
char *msg[] = {
"cd: cd [-L|[-P [-e]] [-@]] [dir]\n",
"    Change the shell working directory.\n",
"\n",
"    Change the current directory to DIR.  The default DIR is the value of the\n",
"    HOME shell variable.\n",
"\n",
"    The variable CDPATH defines the search path for the directory containing\n",
"    DIR.  Alternative directory names in CDPATH are separated by a colon (:).\n",
"    A null directory name is the same as the current directory.  If DIR begins\n",
"    with a slash (/), then CDPATH is not used.\n",
"\n",
"    If the directory is not found, and the shell option `cdable_vars' is set,\n",
"    the word is assumed to be  a variable name.  If that variable has a value,\n",
"    its value is used for DIR.\n",
"\n",
"    Options:\n",
"        -L      force symbolic links to be followed: resolve symbolic links in\n",
"        DIR after processing instances of `..'\n",
"        -P      use the physical directory structure without following symbolic\n",
"        links: resolve symbolic links in DIR before processing instances\n",
"        of `..'\n",
"        -e      if the -P option is supplied, and the current working directory\n",
"        cannot be determined successfully, exit with a non-zero status\n",
"        -@  on systems that support it, present a file with extended attributes\n",
"            as a directory containing the file attributes\n",
"\n",
"    The default is to follow symbolic links, as if `-L' were specified.\n",
"    `..' is processed by removing the immediately previous pathname component\n",
"    back to a slash or the beginning of DIR.\n",
"\n",
"    Exit Status:\n",
"    Returns 0 if the directory is changed, and if $PWD is set successfully when\n",
"    -P is used; non-zero otherwise.\n",
NULL
};

	for (i = 0; msg[i] != NULL; i++)
		write(STDOUT_FILENO, msg[i], strlen(msg[i]));

	return (EXIT_SUCCESS);
}
