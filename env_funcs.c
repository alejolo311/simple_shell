#include "hsh.h"
lenv_s *cenv(char **env)
{
	int i;
	lenv_s *lenv;

	lenv = NULL;
	for (i = 1; env[i] != NULL; i++)
		add_node(&lenv, env[i]);
	return (lenv);

}
/**
 * add_node - add a new node to a list
 * a blank line
 * @head: the head of list
 * @str: the string to put in the new node
 * Description: add a new node to a list
 * section header: the header of this function is lists.h)
 * Return: the head of the list.
 */
lenv_s *add_node(lenv_s **head, char *str)
{
	lenv_s *node;
	char *_str;

	if (str == NULL)
		return (NULL);
	node = malloc(sizeof(lenv_s));
	if (node == NULL)
		return (NULL);
	_str = strdup(str);
	if (_str == NULL)
	{
		free(node);
		return (NULL);
	}
	node->var = _str;
	node->next = *head;
	*head = node;
	return (*head);
}
size_t print_list(lenv_s **head)
{
	int i;

	lenv_s *h = *head;	

	for (i = 0; h ; i++)
	{
		if (h->var == '\0')
			printf("[0] (nil)\n");
		else
			printf("%s\n", h->var);
		h = h->next;
	}

	return (i);
}

char **menv(lenv_s **head)
{
	int i;
	lenv_s *h = *head;
	char **lenv;

	for (i = 0; h; i++)
		h = h->next;
	lenv = malloc(sizeof(char *) * (i + 1));
	h = *head;
	for (i = 0; h; i++)
		lenv[i] = h->var;
	lenv[i] = NULL;

	return (lenv);
}



