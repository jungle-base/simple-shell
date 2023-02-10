# Simple Shell in C

This is an implementation of a simple shell in C. The shell allows users to type in commands and execute them. The shell terminates when the user types in `exit`.

## Requirements

- A C compiler (such as GCC)

## Building and Running the Shell

To build the shell, simply run the following command in the project's root directory:

`$ make`

This will compile the source code and generate the executable `shell`. To run the shell, simply run the following command:

`$ ./hsh`

The shell will start and display a prompt. The prompt will wait for the user to type in a command. A command line always ends with a new line.

## Directory Structure

The project consists of the following files:

- `main.c`: The entry point of the shell.
- `parser.c`: Implementation of the `parse_input` function.
- `parser.h`: Header file for the `parse_input` function.
- `utils.c`: Implementation of the `print_command` and `free_command` functions.
- `utils.h`: Header file for the `print_command` and `free_command` functions.
- `Makefile`: Makefile for building the shell.
- `README.md`: This file.

## Code Conventions

The source code follows the [Betty coding style](https://github.com/holbertonschool/Betty). The documentation follows the [Betty documentation style](https://github.com/holbertonschool/Betty).

