#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "alias.h"
#include "builtin.h"
#include "utils.h"

char *get_command(char *cmd) {
    char *command = strtok(cmd, " \t\n");
    return command;
}

int run_builtin(char *command, char **argv) {
  if (strcmp(command, "exit") == 0) {
    builtin_exit(argv);
    return 0;
  } else if (strcmp(command, "env") == 0) {
    builtin_env();
    return 0;
  } else if (strcmp(command, "setenv") == 0) {
    builtin_setenv(argv);
    return 0;
  } else if (strcmp(command, "unsetenv") == 0) {
    builtin_unsetenv(argv);
    return 0;
  } else if (strcmp(command, "cd") == 0) {
    builtin_cd(argv);
    return 0;
  } else if (strcmp(command, "alias") == 0) {
    return builtin_alias(argv);
  }
  return -1;
}

void free_argv(char **argv) {
  int i = 0;
  while (argv[i]) {
    free(argv[i]);
    i++;
  }
  free(argv);
}
