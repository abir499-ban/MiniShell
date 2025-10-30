# MiniShell
This is a basic command-line shell implemented in C++ that demonstrates how system calls like `fork()`, `execvp()`, and `wait()` work under the hood. It serves as an educational project for understanding process creation and management in Unix-like operating systems.

------------------------------------------------

Uptil these things have been implemented:
1. Input Parsing.
2. Process creation.
3. Parent and Child Process Handling.
4. Built-in Commands like `cd` and `history`.
5. Command Chaining using `;` , `&&` , `||`
6. IO redirection from terminal to file. Read more about [here](https://github.com/abir499-ban/MiniShell/blob/main/fileRedirection.md)

----------------------------------
Terminologies related what I have done till now:

1. Parent Process: A process that initiates the creation of another process. By default , `init()` is the utlimate parent process in a UNIX-based OS.

2. Child Process: A process created by another process (the parent process), allowing multi-processing and efficient resource management in operating systems.

3. Zombie Process: A child process becomes a zombie process when it has terminated but its parent process has not waited for it, and hence its status is not yet cleaned in the PCB.

----------------------------------
System Calls used till now:
1. `fork()` : Creates a new child process by duplicating the current (parent) process.

2. `exeecvp()` : Replaces the current process image with a new program.

3. `wait()` : Pauses the parent process until any one child process terminates.

4. `chdir()` : Changes the current working directory of the calling process.

---------
Built-in Commands / Shell primitve commands that are implemented

`cd`
`history`

------------------------------------------
Commands to run:

1. ```bsh
      make
     ```
2. ```
      ./miniShell
   ```
-----------------------------------------

Things to be implemented:
1. Backgroung Jobs
2. Input / Output Redirection
3. Piping

   WIP......................................
