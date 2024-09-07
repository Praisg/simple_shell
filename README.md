<b>Simple Shell</b>

Description
This project is a simple UNIX command line interpreter. It provides basic command line functionality and executes commands entered by the user.
Features
Simple Shell 0.1

    Display a prompt and wait for the user to type a command. A command line always ends with a new line.
    The prompt is displayed again each time a command has been executed.
    The command lines are simple, no semicolons, no pipes, no redirections, or any other advanced features.
    The command lines are made only of one word. No arguments will be passed to programs.
    If an executable cannot be found, print an error message and display the prompt again.
    Handle errors.
    Handle the “end of file” condition (Ctrl+D).

Simple Shell 0.2

    Handle command lines with arguments.

Simple Shell 0.3

    Handle the PATH.
    Fork must not be called if the command doesn’t exist.

Simple Shell 0.4

    Implement the exit built-in, that exits the shell.
        Usage: exit

Simple Shell 1.0

    Implement the env built-in, that prints the current environment.

Usage
shell will be compiled this way:
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
   
![Screenshot 2024-09-07 042145](https://github.com/user-attachments/assets/99527e10-f219-4be0-b218-7c6cb070e070)

