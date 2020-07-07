/* OSTEP Homework
 * Chapter 5, Question 5
 * 
 * Now write a program that uses wait() to wait for the child process to finish in the parent.
 * What does wait() return? What happens if you use wait() in the child?
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    pid_t parent_pid = getpid();
    int rc = fork();
    
    if (rc < 0) {
        fprintf(stderr, "Error: fork failed.\n");
        exit(1);
    }
    else if (rc == 0) {
        /* Child process */
        int *wstatus = malloc(sizeof(int));
        wait(wstatus);

        printf("Hello\n");

        if (WIFEXITED(*wstatus))
            printf("I am the child process.\n");
        else
            printf("How would I even get here?\n");

        free(wstatus);
    }
    else {
        /* Parent process */
        int *wstatus = malloc(sizeof(int));
        wait(wstatus);

        printf("Goodbye\n");

        if (WIFEXITED(*wstatus))
            printf("Child exited normally.\n");
        else
            printf("Child did not exit normally.\n");

        free(wstatus);
    }

    return 0;
}
