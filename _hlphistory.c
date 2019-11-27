#include "hsh.h"

int prn_hlphistory(void);

/**
 * _hlphistory - function help
 * desc: print the help of the builtins
 * @av: the parameters
 * @e: the counter
 * @lenv: the enviroment list
 * Return: EXIT_SUCCESS in success.
 */
int _hlphistory(char **av, lenv_s **lenv, unsigned int *e)
{
char msg[120];

	(void) lenv;
	(void) e;
	if (_strcmp(av[2], "-d") == 0)
	{
		sprintf(msg, "history - Display or manipulate the history list.\n");
		write(STDOUT_FILENO, msg, strlen(msg));
	}
	else if (_strcmp(av[2], "-s") == 0)
	{
		sprintf(msg, "history: history [-c] [-d offset] [n] or history ");
		sprintf(msg, "%s-anrw [filename] or history -ps arg [arg...]\n", msg);
		write(STDOUT_FILENO, msg, strlen(msg));
	}
	else
		prn_hlphistory();

	return (EXIT_SUCCESS);
}

/**
 * prn_hlphistory - Print the build
 * Return: -19 in exit case, 1 in success, 0 in no exec
 */
int prn_hlphistory(void)
{
int i; /* Line printing counter */
char *msg[] = {
"history: history [-c] [-d offset] [n] or history ",
"-anrw [filename] or history -ps arg [arg...]\n",
"  Display or manipulate the history list.\n",
"\n",
"  Display the history list with line numbers, prefixing each modified\n",
"    entry with a `*'.  An argument of N lists only the last N entries.\n",
"\n",
"  Options:\n",
"    -c        clear the history list by deleting all of the entries\n",
"    -d offset delete the history entry at offset OFFSET.\n",
"\n",
"    -a        append history lines from this session to the history file\n",
"    -n        read all history lines not already read from the history file\n",
"    -r        read the history file and append the contents to the history\n",
"      list\n",
"    -w        write the current history to the history file\n",
"      and append them to the history list\n",
"\n",
"    -p        perform history expansion on each ARG and display the result\n",
"      without storing it in the history list\n",
"    -s        append the ARGs to the history list as a single entry\n",
"\n",
"  If FILENAME is given, it is used as the history file.  Otherwise,\n",
"  if $HISTFILE has a value, that is used, else ~/.bash_history.\n",
"\n",
"  If the $HISTTIMEFORMAT variable is set and not null, its value is used\n",
"  as a format string for strftime(3) to print the time stamp associated\n",
"  with each displayed history entry.  No time stamps are printed otherwise.\n",
"\n",
"  Exit Status:\n",
"  Returns success unless an invalid option is given or an error occurs.\n",
NULL
};

	for (i = 0; msg[i] != NULL; i++)
		write(STDOUT_FILENO, msg[i], strlen(msg[i]));

	return (EXIT_SUCCESS);
}
