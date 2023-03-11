#ifndef MAIN_H
#define MAIN_H

/* Header files */

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/*Global Variables*/

extern char **environ;
extern char *newline;


/*Prototypes*/

int execute(char **args);
char *read_line(void);
char **tokenize(char *buffer);

#endif
