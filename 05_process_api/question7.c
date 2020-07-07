/* OSTEP Homework
 * Chapter 5, Question 7
 * 
 * Write a program that creates a child process, and then in the child closes
 * standard output (STDOUTFILENO). What happens if the child calls printf()
 * to print some output after closing the descriptor?
 */

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    pid_t rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Error: fork failed.\n");
        exit(1);
    }
    else if (rc == 0) {
        /* Child Process */
        printf("Closing standard output...\n");
        fclose(stdout);
        fprintf(stdout, "The quick brown fox jumps over the lazy dog.");
    }

    return 0;
}
