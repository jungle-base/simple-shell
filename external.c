#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include "external.h"

int run_external(char *command, char **argv)
{
    char *path = getenv("PATH");
    char *directory;
    char executable_path[1024];
    pid_t pid;

    if (path == NULL)
        path = ":/bin:/usr/bin";

    directory = strtok(path, ":");
    while (directory != NULL)
    {
        snprintf(executable_path, sizeof(executable_path), "%s/%s", directory, command);
        if (access(executable_path, X_OK) == 0)
            break;

        directory = strtok(NULL, ":");
    }

    if (directory == NULL)
    {
        fprintf(stderr, "%s: command not found\n", command);
        return -1;
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return -1;
    }
    else if (pid == 0)
    {
        if (execv(executable_path, argv) == -1)
        {
            perror("execv");
            exit(1);
        }
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }

    return 0;
}
