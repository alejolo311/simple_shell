#include "hsh.h"
/**
 * _unsetenv - function setenv
 * desc: set a enviroment variable
 * @argv: the parameters
 * @execnt: the counter
 * @lenv: the enviroment
 * Return: 1 in success.
 */
int _unsetenv(char **argv, lenv_s **lenv, unsigned int *execnt)
{
	unsigned int i;
	lenv_s *h;
	char *var;

	(void)execnt;
	h = *lenv;
	if(argv[2] && argv[3] == NULL)
	{
		for (i = 0; h; i++)
		{
			var = h->var;
			if (strncmp(var, argv[2], strlen(argv[2])) == 0)
			{
				delete_node(lenv, i);
				break;
			}
			else
			{
				h = h->next;
			}
		}
	}
	return (1);
}
/**
 * delete_node - thsi function delete a node
 * @head: the head of list
 * @index: the index to put the delete node
 * Description: this function delete a node
 * section header: the header of this function is hsh.h
 * Return: 1 in success -1 in failure
 **/
int delete_node(lenv_s **head, unsigned int index)
{
	lenv_s *actual, *next;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	actual = *head;

	if (index == '\0')
	{
		*head = actual->next;
		free(actual);
		return (1);
	}

	for (i = 0; actual && i < index - 1; i++)
		actual = actual->next;

	if (actual == NULL || actual->next == NULL)
		return (-1);

	next = actual->next->next;
	free(actual->next);
	actual->next = next;
	return (1);
}
