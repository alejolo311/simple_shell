#include "hsh.h"

/**
 * main - Main function for the simple shell
 * @argc: Quantity of parameters
 * @argv: The end NULL list of parameters
 *
 * Return: Always 0
 */
int main (int argc, char **argv)
{
	if (argc > 1)
		myexec(--argc, ++argv);
	else
		interact();

	return (0);
}
