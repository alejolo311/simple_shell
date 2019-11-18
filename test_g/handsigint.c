#include "hsh.h"

/**
 * handsigint - Function that controls the signal Ctrl-C
 * @sign: The signal
 *
 * Return: Always 0
 */
void handsigint(int sign)
{
	(void) sign;
	/* write(STDIN_FILENO, " \n", 2); */
}
