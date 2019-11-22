#include "hsh.h"

/**
 * savehist - function history
 * desc: print the history of commands
 * Return: EXIT_SUCCESS in success.
 */
int savehist(void)
{
int fd;         /* File Descriptor */
int qty;
char filename[120], *home;
commhist_s *head = NULL, *tail = NULL, *node = NULL;

	currhist(&head, &tail);
	if (head == NULL)
		return (EXIT_SUCCESS);
	if (tail == NULL)
		return (EXIT_SUCCESS);

	home = getenv("HOME");
	sprintf(filename, "%s/%s", home, HISTORY_FILE);
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd <= -1)
		return (-1);

	node = head;
	while (node != NULL)
	{
		qty = write(fd, node->cmd, strlen(node->cmd));
		if (qty < 1)
			return (-1);
		qty = write(fd, "\n", 1);
		if (qty < 1)
			return (-1);
		node = node->next;
	}
	if (close(fd) == -1)
		return (-1);

	return (EXIT_SUCCESS);
}
