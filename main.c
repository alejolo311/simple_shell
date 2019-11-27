#include "hsh.h"

/**
 * main - Main function for the simple shell
 * @argc: Quantity of parameters
 * @argv: The end NULL list of parameters
 * @env: The variables from the environment
 *
 * Return: Always 0
 */
int main(int argc, char **argv, char **env)
{
	unsigned int execnt = 1; /* Count how many executions */
	int read = 0;
	lenv_s *lenv;

	lenv = cenv(env);
	signal(SIGINT, handsigint);
	loadhist(&lenv);

	if (argc > 1)
		inputfile(argc, argv, &lenv, &execnt);
	else
		read = interact(argv, &lenv, &execnt);

	path("FLUSH", &lenv);
	savehist(&lenv);
	free_list(&lenv);
	return (read);
}
