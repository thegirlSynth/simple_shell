# C - Simple Shell
A simple UNIX command interpreter written as part of the low-level programming and algorith program at ALX-Holberton School.
It reads commands from either a file or standard input and executes them.

## Compilation
Files are compiled with `gcc` with the following flags:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89`

---

The shell works like this in interactive mode:

    $ ./hsh
    ($) /bin/ls
    hsh main.c shell.c
    ($)
    ($) exit
    $

But also in non-interactive mode:

    $ echo "/bin/ls" | ./hsh
    hsh main.c shell.c test_ls_2
    $
    $ cat test_ls_2
    /bin/ls
    /bin/ls
    $
    $ cat test_ls_2 | ./hsh
    hsh main.c shell.c test_ls_2
    hsh main.c shell.c test_ls_2
    $
