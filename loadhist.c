#include "hsh.h"

/**
 * loadhist - function history
 * desc: print the history of commands
 * @lenv: list
 * Return: EXIT_SUCCESS in success.
 */
int loadhist(lenv_s **lenv)
{
int fd;         /* File Descriptor */
int qty, c = 0;
char filename[120], *home, buf, *av[3], line[256];
	home = _getenv("HOME", lenv);
	sprintf(filename, "%s/%s", home, HISTORY_FILE);
	fd = open(filename, O_RDWR);
	if (fd <= -1)
		return (-1);

	do {
		qty = read(fd, &buf, 1);
		if (qty > 0)
		{
			if (buf == '\n')
			{
				line[c] = '\0';
				c = 0, av[0] = line;
				av[1] = line, av[2] = NULL;
				addhist(av);
			}
			else
			{
				line[c] = buf;
				c += qty;
			}
		}
		if (qty <= -1)
			return (0);
	} while (qty > 0);

	if (close(fd) == -1)
		return (-1);

	return (EXIT_SUCCESS);
}
