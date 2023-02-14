#ifndef ARGUMENTS_H
#define ARGUMENTS_H

char **get_argv(char *cmd);
char *expand_variables(char *line);

#endif /* ARGUMENTS_H */