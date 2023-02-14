#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#include "alias.h"

#define MAX_ALIASES 10

extern char **environ;

typedef struct Shell
{
  int alias_count;
  Alias *aliases[MAX_ALIASES];
  char **environment;
} Shell;

void init_shell(Shell *shell);
void free_shell(Shell *shell);
char **copy_environ(void);
int run_file_input(char *filename);
int run_interactive_mode(void);

#endif /* SHELL_H */
