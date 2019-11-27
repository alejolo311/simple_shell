#include "hsh.h"
/**
 * _getenv - get the enviroment
 * desc: get the enviroment
 * @name : the variable to found
 * @lenv: the list.
 * Return: the varaible o null
 **/
char *_getenv(char *name, lenv_s **lenv)
{
	lenv_s *h;
	char *var;
	int i;

	h = *lenv;
	for (i = 0; h; i++, h = h->next)
	{
		var = h->var;
		if (_strncmp(var, name, _strlen(name)) == 0)
			return (var + (_strlen(name) + 1));
	}
	return (NULL);
}
