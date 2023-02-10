#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "utils.h"

/**
 * parse_input - Tokenizes an input string and returns a Command structure.
 * @input: The input string to tokenize.
 *
 * Return: A pointer to the Command structure on success, NULL on failure.
 */
Command *parse_input(char *input)
{
  Command *cmd;
  char *token;

  if (!input)
    return (NULL);

  cmd = malloc(sizeof(Command));
  if (!cmd)
  {
    perror("malloc");
    return (NULL);
  }

  cmd->argc = 0;
  cmd->argv = malloc(MAX_ARGS * sizeof(char *));
  if (!cmd->argv)
  {
    perror("malloc");
    free(cmd);
    return (NULL);
  }

  token = strtok(input, " ");
  while (token && cmd->argc < MAX_ARGS)
  {
    cmd->argv[cmd->argc] = strdup(token);
    if (!cmd->argv[cmd->argc])
    {
      perror("strdup");
      free_command(cmd);
      return (NULL);
    }
    cmd->argc++;
    token = strtok(NULL, " ");
  }

  cmd->argv[cmd->argc] = NULL;

  return (cmd);
}

