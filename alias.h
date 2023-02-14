#ifndef ALIAS_H
#define ALIAS_H

typedef struct alias {
  char *name;
  char *value;
}Alias;

void add_alias(char *name, char *value);
int find_alias(char *name); 
void free_alias(Alias *alias);
int builtin_alias(char **argv);

#endif /* ALIAS_H */

