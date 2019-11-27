#include "hsh.h"

/**
 * sizehist - function history
 * @lenv: the list
 * desc: Get the number of lines in the history file
 * Return: NUMBER oF LINES in success.
 */
int sizehist(lenv_s **lenv)
{
int fd;         /* File Descriptor */
int qty, c = 0;
char filename[120], *home, buf;

	home = _getenv("HOME", lenv);
	sprintf(filename, "%s/%s", home, HISTORY_FILE);
	fd = open(filename, O_RDWR);
	if (fd <= -1)
		return (-1);

	do {
		qty = read(fd, &buf, 1);
		if (qty <= -1)
			return (0);
		if (qty > 0)
			if (buf == '\n')
				c++;
	} while (qty > 0);

	if (close(fd) == -1)
		return (-1);

	return (c);
}
