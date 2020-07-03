/* OSTEP Homework
 * Chapter 5, Question 3
 * 
 * Write another program using fork().
 * The child process should print “hello”; the parent process should print “goodbye”.
 * You should try to ensure that the child process always prints first; can you do
 * this without calling wait() in the parent?
 */

#include <sys/types.h>
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
        printf("Hello\n");
        kill(parent_pid, SIGCONT);
    }
    else {
        /* Parent process */
        kill(parent_pid, SIGSTOP);
        printf("Goodbye\n");
    }
    return 0;
}
