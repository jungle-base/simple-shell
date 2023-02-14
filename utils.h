#ifndef UTILS_H
#define UTILS_H

char *get_command(char *cmd);
int run_builtin(char *command, char **argv);
void free_argv(char **argv);

#endif