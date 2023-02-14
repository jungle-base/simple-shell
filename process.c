#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arguments.h"
#include "command.h"
#include "utils.h"
#include "external.h"
#include "process.h"


int process_command(char *command) {
    char *trimmed_command = trim_whitespaces(command);
    int status = 0;
    int i;
    char **commands;
    int command_count;
    char *cur_command;
    char *cur_command_expanded;
    char **argv;
    char *path;

    if (strlen(trimmed_command) == 0 || trimmed_command[0] == '#') {
        return status;
    }

    commands = split_commands(trimmed_command, ";");
    command_count = count_commands(commands);

    for (i = 0; i < command_count; i++) {
        if ((cur_command = trim_whitespaces(commands[i])) == NULL) {
            continue;
        }

        if (strlen(cur_command) == 0 || cur_command[0] == '#') {
            continue;
        }

        cur_command_expanded = expand_variables(cur_command);
        argv = get_argv(cur_command_expanded);

        if (run_builtin(cur_command_expanded, argv) == 0) {
            continue;
        } else {
            path = get_command(cur_command_expanded);
            if (path == NULL) {
                fprintf(stderr, "%s: command not found\n", argv[0]);
            } else {
                run_external(path, argv);
            }
        }

        free(cur_command_expanded);
        free_argv(argv);
    }

    free_commands(commands, command_count);

    return status;
}
