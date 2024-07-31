# Custom-Shell
**Custom Command Interpreter**

## Overview

This project implements a basic command interpreter (shell) in C, designed to read user commands and support input and output redirection, pipelining, and command history management. The shell manages signal processing for child process cleanup, ensures memory management for command history and arguments, and uses fork and execvp for executing commands while handling errors effectively. It includes a Makefile for easy compilation and supports file compression and decompression with zip and unzip commands. Additionally, the shell provides the `wc` command to count lines, words, and characters in files or standard input, and the `help` command to display usage information for specific commands, offering general help if no command is specified.

## Features

- **Makefile:** Includes a `Makefile` for conveniently compiling the shell.

- **Command Execution:** Executes commands using `fork` and `execvp`.

- **Input Redirection:** Redirects input from a file using `<`.

- **Output Redirection:** Redirects output to a file using `>`.

- **Output Append Redirection:** Appends output to a file using `>>`.

- **Pipelining:** Chains commands using `|`.

- **Built-in Commands:**

  - `cd [dir]`: Change the current working directory.

  - `pwd`: Print the current working directory.

  - `history`: Show the history of commands entered.

  - `sort [-r]`: Sort a list of numbers in ascending order by default. If -r is specified, it sorts the numbers in reverse order.

  - `wc [-l] [-w] [-c] [FILES...]`: Print the number of lines, words, and characters in files. If no files are given, it reads from standard input.

  - `help [command]`: Display usage information for a specific command. If no command is specified, show general help.

- **File Compression and Decompression:**

  - `zip [input_file] [output_file]`: Compresses the input file to the specified output file.

  - `unzip [input_file] [output_file]`: Decompresses the input file to the specified output file.

- **Command History:** Maintains and displays a history of executed commands.

- **Signal Handling:** Properly handles signals, such as reaping zombie processes.

- **Error Handling:** Gracefully handles common errors related to redirection and command execution.

- **Interactive Prompt:** Continuously prompts for user input until `exit` is entered.

## Prerequisites

- C compiler (e.g., `gcc`)
- POSIX-compatible operating system

## Compilation

To compile the shell, use the following command:

```sh
make
```

## Usage

Run the compiled shell executable:
```sh
cd build
./main
```

The shell will display a prompt (`cssh$`) where you can enter commands.

## Command Examples

- **Run a command:**
```sh
cssh$ ls -l
```

- **Input redirection:**
```sh
cssh$ cat < input.txt
```

- **Output redirection:**
```sh
cssh$ echo "Hello, World!" > output.txt
```

- **Append output redirection:**
```sh
cssh$ echo "Appending text" >> output.txt
```
- **Command piping:**
```sh
cssh$ ls -l | grep "txt"
```

- **Change directory:**
```sh
cssh$ cd /path/to/directory
```

- **Print working directory:**
```sh
cssh$ pwd
```

- **View command history:**
```sh
cssh$ history
```

- **Sort Numbers:**
```sh
cssh$ sort 3.6 1 4 1.1 5 9 2.7 6 5.3 3 5
cssh$ sort -r 3.6 1 4 1.1 5 9 2.7 6 5.3 3 5
```

- **Count lines, words, and characters in a file:**
```sh
cssh$ wc -l file.txt
cssh$ wc -w file.txt
cssh$ wc -c file.txt
```

or
```sh
cssh$ wc file.txt
```

- **Display help for a command:**
```sh
cssh$ help history
cssh$ help zip
```

- ****
```sh
cssh$ help
```

- **Zip a file:**
```sh
cssh$ zip example.txt example.zip
```

or with default output file name:
```sh
cssh$ zip example.txt
```

- **Unzip a file:**
```sh
cssh$ unzip example.zip example.txt
```

or with default output file name:
```sh
cssh$ unzip example.zip
```

- **Exit the shell:**
```sh
cssh$ exit
```

## Error Handling

- If multiple redirection operators are used incorrectly, the shell will print an error message.
- Common errors include:
  - Two or more input redirection operators (`<`).
  - Multiple output redirection operators (`>` or `>>`).
  - File access issues during redirection.
- Errors in command execution and piping will be reported, with details provided by `perror`.