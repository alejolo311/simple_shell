#include "hsh.h"
/**
 * _strlen - this functions prints the lenght of a string
(* a blank line
*@s: string to print.
* Description: this function prints the lenght of a string?
(* section header: the header of this function is holberton.h)*
* Return: retunrn the lenght in int
*/
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}
