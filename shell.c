#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#include "shell.h"
#include "process.h"

char **copy_environ(void)
{
    int i, count = 0;
    char **envp;
    while (environ[count] != NULL)
        count++;
    envp = (char **) malloc((count+1) * sizeof(char *));

    for (i = 0; environ[i]; i++)
    {
        envp[i] = strdup(environ[i]);
        if (!envp[i])
        {
            perror("strdup");
            exit(EXIT_FAILURE);
        }
    }
    envp[i] = NULL;
    return envp;
}


void init_shell(Shell *shell)
{
    shell->alias_count = 0;
    shell->environment = copy_environ();
}

void free_shell(Shell *shell)
{
    int i;
    for (i = 0; i < shell->alias_count; i++)
    {
        free_alias(shell->aliases[i]);
    }
    for (i = 0; shell->environment[i]; i++)
    {
        free(shell->environment[i]);
    }
    free(shell->environment);
    free(shell);
}

int run_file_input(char *filename)
{
    int fd, ret = 0;
    char *commands = NULL;
    size_t size = 0;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    ret = read(fd, &size, sizeof(size_t));
    if (ret == -1)
    {
        perror("Error reading file");
        return 1;
    }

    commands = (char *) malloc(size + 1);
    if (!commands)
    {
        perror("Error allocating memory");
        return 1;
    }

    ret = read(fd, commands, size);
    if (ret == -1)
    {
        perror("Error reading file");
        free(commands);
        return 1;
    }

    commands[size] = '\0';

    ret = process_command(commands);

    free(commands);
    close(fd);

    return ret;
}

int run_interactive_mode(void)
{
  char *line = NULL;
  size_t line_size = 0;
  ssize_t line_len;
  int ret = 0;

  while (1)
  {
    printf("$ ");
    line_len = getline(&line, &line_size, stdin);
    if (line_len == -1)
    {
      ret = -1;
      break;
    }
    process_command(line);
  }
  free(line);
  return ret;
}
