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
	if (argc > 1)
		myexec(argc, argv, env);
	else
		interact(argc, argv, env);

	return (0);
}
