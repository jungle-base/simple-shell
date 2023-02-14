#include "builtin.h"

void builtin_exit(char **args) {
  int status = 0;
  if (args[1] != NULL) {
    status = atoi(args[1]);
  }
  exit(status);
}

void builtin_env() {
  extern char **environ;
  int i;
  for (i = 0; environ[i] != NULL; i++) {
    printf("%s\n", environ[i]);
  }
}

void builtin_setenv(char **args) {
  if (args[1] == NULL || args[2] == NULL) {
    fprintf(stderr, "setenv: too few arguments\n");
    return;
  }
  if (setenv(args[1], args[2], 1) != 0) {
    perror("setenv");
  }
}

void builtin_unsetenv(char **args) {
  if (args[1] == NULL) {
    fprintf(stderr, "unsetenv: too few arguments\n");
    return;
  }
  if (unsetenv(args[1]) != 0) {
    perror("unsetenv");
  }
}

void builtin_cd(char **args) {
  char *dir;
  if (args[1] == NULL) {
    dir = getenv("HOME");
    if (dir == NULL) {
      fprintf(stderr, "cd: HOME not set\n");
      return;
    }
  } else if (strcmp(args[1], "-") == 0) {
    dir = getenv("OLDPWD");
    if (dir == NULL) {
      fprintf(stderr, "cd: OLDPWD not set\n");
      return;
    }
    printf("%s\n", dir);
  } else {
    dir = args[1];
  }
  if (chdir(dir) != 0) {
    perror("cd");
  } else {
    setenv("OLDPWD", getenv("PWD"), 1);
    setenv("PWD", dir, 1);
  }
}

