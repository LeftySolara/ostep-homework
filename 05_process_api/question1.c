/* OSTEP Homework
 * Chapter 5, Question 1
 *
 * Write a program that calls fork(). Before calling fork(), have the main
 * process access a variable (e.g., x) and set its value to something (e.g., 100).
 * What value is the variable in the child process? What happens to the variable
 * when both the child and parent change the value of x?
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int x = 100;
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Error: fork failed.\n");
        exit(1);
    }
    else if (rc == 0) {
        /* New child process. */
        printf("Hello, I am the child process with PID %d.\n", (int)getpid());
        printf("Initial value of x in child process: %d.\n", x);
        x = 50;
        printf("Value of x in child process after change: %d\n", x);
    }
    else {
        /* Parent process. */
        printf("Hello, I am the parent process with PID %d.\n", (int)getpid());
        printf("Initial value of x in parent process: %d.\n", x);
        x = 25;
        printf("Value of x in parent process after change: %d.\n", x);
    }

    return 0;
}
