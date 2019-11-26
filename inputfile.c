#include "hsh.h"

int inputfile(int argc, char **argv, lenv_s **lenv, unsigned int *execnt)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

   
   (void) argc;
   (void) lenv;
   (void) execnt;
   
   
    fp = fopen(argv[1],"r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
	    myexec(argc,line, lenv, execnt);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
