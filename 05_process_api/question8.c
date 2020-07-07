/* OSTEP Homework
 * Chapter 5, Question 8
 * 
 * Write a program that creates two children, and connects the standard output of one
 * to the standard input of the other, using the `pipe()` system call.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char **argv)
{
    /* Create the pipe */
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    if (fork() == 0) {
        /* Child process */
        close(STDOUT_FILENO);
        dup(pipefd[1]);  /* Replace stdout with pipe */
        close(pipefd[0]);
        close(pipefd[1]);

        char *prog = "/bin/ls";
        char *const args[] = {prog, "-l", NULL};
        execve(prog, args, NULL);
        perror("execve of ls");
        exit(1);
    }

    if (fork() == 0) {
        /* Second child process */
        close(STDIN_FILENO);
        dup(pipefd[0]); /* Replace stdin with pipe */
        close(pipefd[1]);
        close(pipefd[0]);

        char *prog = "/usr/bin/wc";
        char *const args[] = {prog, "-l", NULL};
        execve(prog, args, NULL);
        perror("execve of wc");
        exit(1);
    }

    close(pipefd[0]);
    close(pipefd[1]);

    wait(0);
    wait(0);

    return 0;
}
