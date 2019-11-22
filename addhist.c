#include "hsh.h"

/**
 * addhist - add to the history list
 * @argv: the command in a NULL ended stack
 * Return: EXIT_SUCCESS in success.
 */
int addhist(char **argv)
{
	int i = 1, len = 0;
	commhist_s *head = NULL, *tail = NULL, *node = NULL;

	if (argv[0] == NULL || argv == NULL || argv[1] == NULL)
		return (-1);
	currhist(&head, &tail);
	node = malloc(sizeof(commhist_s));
	if (node == NULL)
		return (-1);
	for (i = 1; argv[i] != NULL; i++)
	{
		len += _strlen(argv[i]);
		if (i != 1)
			len++;
	}
	node->cmd = malloc(len + 1);
	if (node->cmd == NULL)
	{
		free(node);
		return (-1);
	}

	node->cmd[0] = '\0';
	for (i = 1; argv[i] != NULL; i++)
	{
		if (i != 1)
			sprintf(node->cmd, "%s ", node->cmd);
		sprintf(node->cmd, "%s%s", node->cmd, argv[i]);
	}
	node->next = NULL;

	if (head == NULL)
	{
		node->id = 0, head = node, tail = node;
		currhist(&head, &tail);
		return (EXIT_SUCCESS);
	}
	node->id = tail->id + 1, tail->next = node, tail = node;
	currhist(&head, &tail);
	return (EXIT_SUCCESS);
}
