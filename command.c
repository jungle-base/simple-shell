#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <sys/wait.h>
#include "command.h"
#include "arguments.h"
#include "utils.h"
#include "external.h"

int count_commands(char **commands) {
    int count = 0, in_quote = 0, escape = 0;
    char *p;

    for (p = *commands; *p != '\0'; p++) {
        if (*p == '\\' && !escape) {
            escape = 1;
        } else if (*p == '"' || *p == '\'') {
            if (!escape) {
                in_quote = !in_quote;
            } else {
                escape = 0;
            }
        } else if (!in_quote && *p == ';') {
            count++;
        } else {
            escape = 0;
        }
    }

    return count + 1;
}

char *trim_whitespaces(char *str)
{
    int n = strlen(str);
    int i = 0, j = n - 1;
    while (str[i] == ' ')
        i++;
    while (str[j] == ' ')
        j--;
    str[j + 1] = '\0';
    return str + i;
}

void free_commands(char **commands, int n_commands)
{
    int i;
    for (i = 0; i < n_commands; i++)
        free(commands[i]);
    free(commands);
}

char **split_commands(char *str, char *delimiter) {
    char **tokens = NULL;
    char *token = strtok(str, delimiter);
    int count = 0;

    while (token != NULL) {
        tokens = realloc(tokens, sizeof(char *) * (count + 1));
        tokens[count] = token;
        count++;

        token = strtok(NULL, delimiter);
    }

    tokens = realloc(tokens, sizeof(char *) * (count + 1));
    tokens[count] = NULL;

    return tokens;
}

