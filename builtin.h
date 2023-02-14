#ifndef BUILTIN_H
#define BUILTIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void builtin_exit(char **args);
void builtin_env();
void builtin_setenv(char **args);
void builtin_unsetenv(char **args);
void builtin_cd(char **args);

#endif /* BUILTIN_H */