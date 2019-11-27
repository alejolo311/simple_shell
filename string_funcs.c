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
/**
 * _strdup - this functions copy a string.
(* a blank line
*@str: the string to copy
* Description: this function copy a string)?
(* section header: the header of this function is holberton.h)*
* Return: this is a void function no return
*/
char *_strdup(char *str)
{
  char *p;
  int i, s;

  i = 0;
  if (str == NULL)
    return (NULL);
  while (str[i] != '\0')
    i++;
  p = malloc(i * sizeof(*str) + 1);
  if (p == NULL)
    return (NULL);
  for (s = 0; s < i; s++)
    *(p + s) = *(str + s);
  *(p + s) = '\0';

  return (p);
}
