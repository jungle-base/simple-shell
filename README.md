# Simple Shell in C

This is a simple shell implementation in C. It provides basic command-line functionality such as running external programs, using environment variables, and running built-in commands.

## Getting Started

To get started, clone the repository and compile the source code by running the following commands:

`$ git clone https://github.com/RasBoluuuma/simple-shell.git`
`$ cd simple-shell`
`$ make`


This will create an executable file named hsh in the project directory.

To run the shell in interactive mode, simply run the hsh executable without any arguments:

`$ ./hsh`

To run a script file, pass the file as an argument to the shell executable:

`$ ./hsh script.sh`

## Usage

The shell supports the following commands:

- cd: change directory
- exit: exit the shell
- env: print environment variables
- setenv: set an environment variable
- unsetenv: unset an environment variable

### Using aliases

The shell also supports the alias command, which you can use to define aliases for commonly used commands. To define an alias, simply run the following command:

`$ alias <alias_name>="<command>"`

For example, to define an alias for the ls -l command, you can run:

`$ alias lsl="ls -l"`

You can then use the alias by simply typing in the alias name:

`$ lsl`

This will run the ls -l command.

In addition to the built-in commands, the shell can run external programs by entering their path or name. The shell also supports command-line arguments and environment variables. To reference an environment variable, use the format $VARNAME or ${VARNAME}.

## Code Conventions

The source code follows the [Betty coding style](https://github.com/holbertonschool/Betty). The documentation follows the [Betty documentation style](https://github.com/holbertonschool/Betty).

## License

This program is licensed under the MIT License. See the LICENSE file for details.

