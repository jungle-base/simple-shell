#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "parser.h"
#include "utils.h"

#define BUFSIZE 1024

/**
 * main - The entry point of the shell.
 *
 * Return: Always program exit status.
 */
int main(void)
{
  char *input = NULL;
  size_t len = 0;
  Command *cmd;
  char *path;
  int pid, status;
  char *dirs;
  char *saveptr;
  char *dir;
  char buf[BUFSIZE];

  while (1)
  {
    printf("$ ");
    if (getline(&input, &len, stdin) == -1) 
    {
      printf("\n");
      break;
    }
    input[strlen(input) - 1] = '\0';
    cmd = parse_input(input);
    if (cmd->argc == 1 && strcmp(cmd->argv[0], "exit") == 0)
    {
      break;
    }
    
    pid = fork();
    if (pid == 0)
    {
      path = getenv("PATH");
      dirs = strdup(path);
      
      for (dir = strtok_r(dirs, ":", &saveptr); dir; dir = strtok_r(NULL, ":", &saveptr))
      {
        snprintf(buf, BUFSIZE, "%s/%s", dir, cmd->argv[0]);
        execve(buf, cmd->argv, NULL);
      }
      free(dirs);
      perror("execve");
      exit(1);
    }
    else if (pid > 0)
    {
      wait(&status);
    }
    else
    {
      perror("fork");
    }
    free_command(cmd);
  }

  free(input);
  return 0;
}


