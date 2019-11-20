#include "hsh.h"
/**
 * check_builtin - check if the input is a built-in
 * desc: check if the command in the inpit is a valid built-in
 * @builtin: the command to check
 * @env: the enviroment
 * Return: -19 in exit case, 1 in success, 0 in no exec
 */
int (*check_builtin(char *builtin))()
{
	int i; /* the counter to itarate the struct to search the correct builtin" */
	builtin_s cmm[] = {	
		{"exit", _ex},
		{"env", _env},	
	/*	{"cd", _cd},
    		{"help", _help},
    		{"history", _history},
    		{"setenv", _setenv},
    		{"unsetenv", _unsetenv}, */
    		{"NULL", NULL}
  	};
	int cmm_len = sizeof(cmm) / sizeof(builtin_s);
	const char *p = builtin;

	if (p != NULL)
	  {
	    for (i = 0; i < cmm_len; i++)
	      {
		if (strncmp(builtin, cmm[i].s, strlen(cmm[i].s)))
		  	return (cmm[i].f);
	      }
	  }
	return (0);
}
