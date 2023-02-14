#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alias.h"

int num_aliases = 0;
Alias *aliases;

void add_alias(char *name, char *value) {
  int index = find_alias(name);
  if (index >= 0) {
    free(aliases[index].value);
    aliases[index].value = strdup(value);
  } else {
    index = num_aliases;
    num_aliases++;
    aliases = realloc(aliases, num_aliases * sizeof(struct alias));
    aliases[index].name = strdup(name);
    aliases[index].value = strdup(value);
  }
}

int find_alias(char *name) {
  int i;
  for (i = 0; i < num_aliases; i++) {
    if (strcmp(aliases[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

void free_alias(Alias *alias) {
  if (!alias) return;
  free(alias->name);
  free(alias->value);
}

int builtin_alias(char **argv) {
  int argc = 0, i;
  char *arg, *equals_pos, *name, *value;

  while (argv[argc]) {
    argc++;
  }
  
  if (argc == 1) {
    for (i = 0; i < num_aliases; i++) {
      printf("%s='%s'\n", aliases[i].name, aliases[i].value);
    }
    return 0;
  }
  
  for (i = 1; i < argc; i++) {
    arg = argv[i];
    equals_pos = strchr(arg, '=');
    if (equals_pos) {
      *equals_pos = '\0';
      name = arg;
      value = equals_pos + 1;
      add_alias(name, value);
    } else {
      int index = find_alias(arg);
      if (index >= 0) {
        printf("%s='%s'\n", aliases[index].name, aliases[index].value);
      } else {
        fprintf(stderr, "alias: %s: not found\n", arg);
      }
    }
  }
  
  return 0;
}
