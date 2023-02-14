#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "shell.h"

int main(int argc, char **argv)
{
  Shell shell;
  
  init_shell(&shell);

  if (argc > 2)
  {
    fprintf(stderr, "Usage: %s [file]\n", argv[0]);
    return 1;
    
  }
  else if (argc == 2)
  {
    return run_file_input(argv[1]);
  }
  else
  {
    return run_interactive_mode();
  }
  free_shell(&shell);
  return (EXIT_SUCCESS);
}



