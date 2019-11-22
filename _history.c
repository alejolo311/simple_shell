#include "hsh.h"

/**
 * _history - function history
 * desc: print the history of commands
 * @argv: the parameters
 * @lenv: the enviroment list
 * @execnt: the comands counter
 * Return: EXIT_SUCCESS in success.
 */
int _history(char **argv, lenv_s **lenv, unsigned int *execnt)
{
char msg[120];
int line;
commhist_s *head = NULL, *tail = NULL, *node = NULL;

	(void) argv;
	(void) lenv;
	(void) execnt;

	currhist(&head, &tail);

	if (head == NULL)
		return (EXIT_SUCCESS);
	if (tail == NULL)
		return (EXIT_SUCCESS);

	line = tail->id % 4096;

	node = head;
	while (node != NULL)
	{
		if (node->id >= line)
		{
			sprintf(msg, "%5d %s\n", node->id, node->cmd);
			write(STDOUT_FILENO, msg, strlen(msg));
		}
		node = node->next;
	}

	return (EXIT_SUCCESS);
}
