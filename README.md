# Minishell

Minishell is a simple shell program that allows you to interact with a computer using a command-line interface. It provides basic shell functionality such as executing commands, handling environment variables, redirections, pipes, and built-in commands.

## Installation

1. Clone the repository or download the source code.
2. Compile the source code using the provided Makefile: make

## Usage

  ./minishell

This will start the Minishell program and display a prompt where you can enter commands.

## Supported Commands

Minishell supports the following built-in commands:

- echo [-n] [string ...]: Display a line of text or the value of a variable.
- cd [directory]: Change the current working directory.
- pwd: Print the current working directory.
- export [name[=value]] ...: Set environment variables.
- unset [name ...]: Unset environment variables.
- env: Display the current environment variables.
- exit [status]: Exit the shell.

In addition to the built-in commands, Minishell can execute external commands by searching for the executable in the directories listed in the PATH environment variable.

## Redirections

Minishell supports the following redirections:

- < file: Redirects the input from a file.
- > file: Redirects the output to a file, overwriting its contents.
- >> file: Redirects the output to a file, appending to its contents.
- << delimiter: Redirects the input until a line containing the delimiter is seen.

## Pipes

Minishell supports pipes (| character) to connect the output of one command to the input of another command.

## Environment Variables

Minishell supports the expansion of environment variables using the $ character followed by the variable name. It also supports the special variable $?, which expands to the exit status of the most recently executed foreground pipeline.

## Signals

Minishell handles the following signals:

- Ctrl-C: Displays a new prompt on a new line.
- Ctrl-D: Exits the shell.
- Ctrl-\: Does nothing.

## Bonus Features

If you have completed all the mandatory requirements of the project, you can implement the following bonus features:

- && and || operators with parentheses for command priorities.
- Wildcards (*) that work for the current working directory.
