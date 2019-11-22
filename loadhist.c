#include "hsh.h"

/**
 * loadhist - function history
 * desc: print the history of commands
 * Return: EXIT_SUCCESS in success.
 */
int loadhist(void)
{
int fd;         /* File Descriptor */
int qty, c = 0;
char filename[120], *home, buf, *av[3], line[256];

	home = getenv("HOME");
	sprintf(filename, "%s/%s", home, HISTORY_FILE);
	fd = open(filename, O_RDWR);
	if (fd <= -1)
		return (-1);

	do {
		qty = read(fd, &buf, 1);
		if (qty <= -1)
			return (0);
		if (buf == '\n')
		{
			if (c > 0)
			{
				line[c] = '\0';
				printf("[%s]::", line);
				c = 0;
				av[0] = NULL;
				av[1] = line;
				av[2] = NULL;
				addhist(av);
			}
		}
		else
		{
			line[c] = buf;
			c += qty;
		}
	} while (qty > 0);

	if (close(fd) == -1)
		return (-1);

	return (EXIT_SUCCESS);
}
