#ifndef PARSER_H
#define PARSER_H

#define MAX_ARGS 128

typedef struct Command
{
  char **argv;
  int argc;
} Command;

/**
 * parse_input - Parse the input string into a Command struct.
 * @input: The input string to parse.
 *
 * Return: Pointer to the Command struct.
 */
Command *parse_input(char *input);

#endif /* PARSER_H */

