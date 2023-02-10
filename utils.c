#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

/**
 * free_command - Frees a Command structure.
 * @cmd: The Command structure to free.
 */
void free_command(Command *cmd)
{
  int i;

  if (!cmd)
    return;

  for (i = 0; i < cmd->argc; i++)
    free(cmd->argv[i]);
  free(cmd->argv);
  free(cmd);
}

/**
 * print_command - Prints a Command structure.
 * @cmd: The Command structure to print.
 */
void print_command(const Command *cmd)
{
  int i;

  if (!cmd)
    return;

  for (i = 0; i < cmd->argc; i++)
    printf("%s ", cmd->argv[i]);
  printf("\n");
}

