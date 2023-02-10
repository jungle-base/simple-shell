#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "utils.h"

/**
 * main - The entry point of the shell.
 *
 * Return: Always program exit status.
 */
int main(void)
{
  char *input = NULL;
  size_t len = 0;
  ssize_t read;
  Command *cmd;

  while ((read = getline(&input, &len, stdin)) != -1)
  {
    input[strcspn(input, "\n")] = '\0';
    cmd = parse_input(input);
    if (!cmd)
      break;

    print_command(cmd);
    free_command(cmd);
  }

  free(input);
  return 0;
}


