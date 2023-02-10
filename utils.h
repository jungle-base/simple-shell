#ifndef UTILS_H
#define UTILS_H

#include "parser.h"

/**
 * print_command - Print the Command struct to stdout.
 * @cmd: The Command struct to print.
 */
void print_command(Command *cmd);

/**
 * free_command - Free the memory used by the Command struct.
 * @cmd: The Command struct to free.
 */
void free_command(Command *cmd);

#endif /* UTILS_H */

