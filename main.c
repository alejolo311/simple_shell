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

	signal(SIGINT, handsigint);

	if (argc > 1)
		myexec(argc, argv, env, &execnt);
	else
		interact(argv, env, &execnt);

	path("FLUSH", env);
	return (0);
}
