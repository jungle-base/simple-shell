#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "arguments.h"

char **get_argv(char *cmd) {
    char *token;
    char **argv = malloc(10 * sizeof(char *));
    int i = 0;

    token = strtok(cmd, " \t\n");
    while (token != NULL && token[0] != '#') {
        argv[i] = token;
        i++;
        token = strtok(NULL, " \t\n");
    }
    argv[i] = NULL;
    return argv;
}

int last_exit_status = 0;

char *expand_variables(char *line) {
  int len = strlen(line);
  int i = 0, j = 0;
  char *expanded = malloc(len + 1);
  if (!expanded) {
    perror("malloc");
    return NULL;
  }
  memset(expanded, 0, len + 1);
  while (i < len) {
    if (line[i] == '$' && i + 1 < len) {
      i++;
      if (line[i] == '?') {
        char status[12];
        sprintf(status, "%d", last_exit_status);
        strcat(expanded, status);
        j += strlen(status);
      } else if (line[i] == '$') {
        char pid[12];
        sprintf(pid, "%d", getpid());
        strcat(expanded, pid);
        j += strlen(pid);
      } else {
        expanded[j++] = '$';
        expanded[j++] = line[i];
      }
    } else {
      expanded[j++] = line[i];
    }
    i++;
  }
  return expanded;
}
