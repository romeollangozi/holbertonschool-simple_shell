# Simple Shell

This project is about creating a simple shell that mimics the fundamental features of the [Bash](https://en.wikipedia.org/wiki/Unix_shell) shell.

## Introduction

This `Simple Shell` is a basic Unix shell that provides a user
interface to interact with the operating system. It reads and executes user commands, supports basic built-in commands, and manages processes. While it lacks the complexity of more advanced shells, this Simple Shell serves as a valuable learning tool for understanding core shell concepts. 

The project's purpose is to provide a starting point for individuals new to shell programming or seeking insights into the fundamental aspects of shell operation.

## Table of Contents

- [Introduction](#introduction)
- [Requirements](#requirements)
- [Installation](#installation)
- [Features](#features)
- [Command Execution](#commandexecution)
- [Examples](#examples)
- [Authors](#authors)

## Requirements

### General
* Allowed editors: `vi`, `vim`, `emacs`
* All files were compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
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

ls command

How is executed in the original shell:
```
root@6a6fc368bfce:~/holbertonschool-simple_shell# ls
AUTHORS  main.h  man_1_simple_shell  README.md  shell.c  token_line.c  token_path.c
```

How is executed in our simple shell:

```
$ls
AUTHORS  hsh  main.h  man_1_simple_shell  README.md  shell.c  token_line.c  token_path.c
$
```

ls -la command

How is executed in the original shell:

```
root@6a6fc368bfce:~/holbertonschool-simple_shell# ls -la
total 52
drwxr-xr-x 3 root root   156 Aug 22 05:10 .
drwx------ 1 root root  4096 Aug 22 05:10 ..
-rw-r--r-- 1 root root   236 Aug 22 03:02 AUTHORS
drwxr-xr-x 8 root root   220 Aug 22 04:57 .git
-rwxr-xr-x 1 root root 17968 Aug 22 05:08 hsh
-rw-r--r-- 1 root root   387 Aug 22 03:04 main.h
-rwxr--r-- 1 root root  3201 Aug 17 03:49 man_1_simple_shell
-rw-r--r-- 1 root root  3843 Aug 22 05:10 README.md
-rw-r--r-- 1 root root  2091 Aug 22 03:09 shell.c
-rw-r--r-- 1 root root   963 Aug 21 02:00 token_line.c
-rw-r--r-- 1 root root   939 Aug 22 04:57 token_path.c
```
How is executed in our simple shell:

```
$ls -la
total 56
drwxr-xr-x 3 root root   156 Aug 22 05:11 .
drwx------ 1 root root  4096 Aug 22 05:11 ..
-rw-r--r-- 1 root root   236 Aug 22 03:02 AUTHORS
drwxr-xr-x 8 root root   220 Aug 22 04:57 .git
-rwxr-xr-x 1 root root 17968 Aug 22 05:11 hsh
-rw-r--r-- 1 root root   387 Aug 22 03:04 main.h
-rwxr--r-- 1 root root  3201 Aug 17 03:49 man_1_simple_shell
-rw-r--r-- 1 root root  4506 Aug 22 05:11 README.md
-rw-r--r-- 1 root root  2091 Aug 22 03:09 shell.c
-rw-r--r-- 1 root root   963 Aug 21 02:00 token_line.c
-rw-r--r-- 1 root root   939 Aug 22 04:57 token_path.c
$
```

### Authors

Romeo LLangozi | [@romeollangozi](https://github.com/romeollangozi)

Izabela Nelaj | [@izabelanelaj](https://github.com/izabela9)

Silvi Marku | [@silvimarku](https://github.com/SilviMarku)

Ergi Lama | [@ergilama](https://github.com/Ergi004)

