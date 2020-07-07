/* OSTEP Homework
 * Chapter 5, Question 6
 * 
 * Write a slight modification of the previous program, this time using waitpid()
 * instead of wait(). When would waitpid() be useful?
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
        waitpid(-1, wstatus, 0);

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
        waitpid(rc, wstatus, 0);

        printf("Goodbye\n");

        if (WIFEXITED(*wstatus))
            printf("Child exited normally.\n");
        else
            printf("Child did not exit normally.\n");

        free(wstatus);
    }

    return 0;
}
