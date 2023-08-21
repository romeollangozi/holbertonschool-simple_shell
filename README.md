# Simple Shell

This project is about creating a simple shell that mimics the [Bash](https://en.wikipedia.org/wiki/Unix_shell) shell but with limited features.

## Introduction

This `Simple Shell` is a basic Unix shell that provides a user
interface to interact with the operating system. It reads and executes user commands, supports basic built-in commands, and manages processes. While it lacks the complexity of more advanced shells, this Simple Shell serves as a valuable learning tool for understanding core shell concepts. 

The project's purpose is to provide a starting point for individuals new to shell programming or seeking insights into the fundamental aspects of shell operation.

## Table of Contents

- [Introduction](#introduction)
- [Requirements](#requirements)
- [Features](#features)
- [Installation](#getting-started)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Requirements

### General
* Allowed editors: vi, vim, emacs
* All files were compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* Betty coding style is followed.
* The simple shell has no known memory leaks

## Installation

Designed to run on `Ubuntu 20.04 LTS`, the simple_shell can be installed as follows:

* Clone the current repository with the command: `git clone` `"https://github.com/romeollangozi/holbertonschool-simple_shell"`
* `cd` in to the cloned directory: `cd holbertonschool-simple_shell`
* Create an executable using: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
* Run the executable using `./hsh`.

## Features
Our simple shell fulfils these features :

* **Prompt Display**: The shell displays a prompt ($ ) where you can input commands.
```
if (isatty(STDIN_FILENO))
      printf("$");
```
* **Repeat Prompt:** After executing a command, the shell displays the prompt again for the next command.
* **Command Line:** The shell supports simple command lines and the ones with arguments.
* **Command Not Found:** If an executable cannot be found, the shell prints an error message and displays the prompt again.
* **Error Handling:** The shell handles errors and provides informative error messages.
* **End of File (Ctrl+D):** The shell handles the "end of file" condition (Ctrl+D) and exits the shell.
* **PATH Handling:** The shell uses the PATH environment variable to locate executables.
* **Built-in Commands:** The shell includes two built-in commands:

   * exit: Exits the shell.
   * env: Prints the current environment variables.

## Command Execution
1. The shell displays a prompt ( $ ).
2. Input a command (e.g., ls) and press Enter.
3. The simple shell uses the `fork` system call to create a child process that will execute the command.
3. In the child process, the simple shell uses the `exec` family of functions (execvp) to load the specified executable and its arguments.
4. The parent process (shell) uses the `wait` system call to wait for the child process to terminate, ensuring synchronization.
5. The `exit status` of the child process is obtained and displayed, providing information about whether the command executed successfully.

### Examples


### Authors

Romeo LLangozi | [@romeollangozi](https://github.com/romeollangozi)
Izabela Nelaj | [@izabelanelaj](https://github.com/izabela9)
Silvi Marku | [@silvimarku](https://github.com/SilviMarku)

