# simple_shell

`simple_shell` is a minimalist shell written in C that aims to replicate basic functionalities of bash.

## Description

`simple_shell` is designed as a basic interactive shell environment. It supports simple system commands like `ls`, `pwd` and allows the use of arguments. It also incorporates a few custom commands such as `sohi` to display an ASCII art image and `calc` for a calculator mode.

## Features

- Executes basic system commands.
- Supports command-line arguments.
- `sohi` command to display ASCII art.
- Calculator mode `calc`.
- `exit` to leave the shell or calculator mode.
- `clear` to clean the terminal display.
- Handles CTRL-D and CTRL-C signals.


## Mandatory tasks

- Write a README / Write a man for your shell.
- Write a beautiful code that passes the Betty checks.
- Write a UNIX command line interpreter.
- Handle command lines with arguments.
- Handle the PATH.
- Implement the exit built-in, that exits the shell.
- Implement the env built-in, that prints the current environment.

## Requirements

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to (why?)

## Author

- [@Iaskasan](https://github.com/Iaskasan/)