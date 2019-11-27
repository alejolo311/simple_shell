#include "hsh.h"

/**
 * currhist - controls the history list
 * @h: the head
 * @t: the tail
 * Return: EXIT_SUCCESS in success.
 */
int currhist(commhist_s **h, commhist_s **t)
{
static commhist_s *head, *tail;

	if (h == NULL)
		head = NULL;
	else if (*h == NULL)
		*h = head;
	else
		head = *h;

	if (t == NULL)
		tail = NULL;
	else if (*t == NULL)
		*t = tail;
	else
		tail = *t;

	return (EXIT_SUCCESS);
}
