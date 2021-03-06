# Process API

In this homework, you are to gain some familiarity with the process management APIs about which you just read. Don’t worry – it’s even more fun than it sounds! You’ll in general be much better off if you find as much time as you can to write some code, so why not start now?

## Questions

1. Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable (e.g., x) and set its value to something (e.g.,100). What value is the variable in the child process? What happens to the variable when both the child and parent change the value of x?

    - The value of `x` in the child process is the same as in the parent process. Because the value was assigned before the call to `fork()`, it gets carried over when the child process receives a copy of the parent's memory space.

    - If both the parent and child processes change the value of `x`, then `x` will change within the two processes separately. For example, if the parent assigns `x = 25`, then `x` will only change within that process and will not affect the child. This is due to the memory spaces of the processes being separate once the call to `fork()` has completed.


2. Write a program that opens a file (with the `open()` system call) and then calls `fork()` to create a new process. Can both the parent and child access the file descriptor returned by `open()`? What happens when they are writing to the file concurrently (i.e., at the same time)?

    - Both the parent and child processes can access the file descriptor at the same time.

    - If both processes attempt to write concurrently, one will overwrite the other.


3. Write another program using `fork()`. The child process should print “hello”; the parent process should print “goodbye”. You should try to ensure that the child process always prints first; can you do this without calling `wait()` in the parent?

    - This can be achieved by using `kill()` to send SIGSTOP and SIGCONT to the parent process.


4. Write a program that calls `fork()` and then calls some form of `exec()` to run the program `/bin/ls`. See if you can try all of the variants of `exec()`, including (on Linux) `execl()`, `execle()`, `execlp()`, `execv()`, `execvp()`, and `execvpe()`.  Why do you think there are so many variants of the same basic call?

    - The variants allow for passing parameters in different forms to fit different situations. For example, some pass an array of strings to be used as environment variables for the new program being run. Others allow the passing of arguments as an array, which is useful when the number of parameters in the exec'ed process are variable. Some also search `PATH` if the given executable can't be found.


5. Now write a program that uses `wait()` to wait for the child process to finish in the parent. What does `wait()` return? What happens if you use `wait()` in the child?

    - `wait()` returns the PID of the terminated child process, or -1 on error. It also sets `errno` if necessary.

    - Calling `wait()` in the child process effectively does nothing because there is no additional process to wait for. The `wait()` call itself returns -1.


6. Write a slight modification of the previous program, this time using `waitpid()` instead of  `wait()`. When would `waitpid()` be useful?

    - `waitpid()` would be useful when the parent process has more than one child.


7. Write a program that creates a child process, and then in the child closes standard output (`STDOUTFILENO`). What happens if the child calls `printf()` to print some output after closing the descriptor?

    - When calling `printf()` after closing `stdout`, nothing is printed.


8. Write a program that creates two children, and connects the standard output of one to the standard input of the other, using the `pipe()` system call.
