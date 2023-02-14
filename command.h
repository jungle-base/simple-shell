#ifndef COMMAND_H
#define COMMAND_H

void free_commands(char **commands, int n_commands);
int count_commands(char **commands);
char *trim_whitespaces(char *str);
char **split_commands(char *str, char *delimiter);

#endif
