/* OSTEP Homework
 * Chapter 5, Question 4
 * 
 * Write a program that calls fork() and then calls some form of exec()
 * to run the program /bin/ls. See if you can try all of the variants of exec(),
 * including (on Linux) execl(), execle(), execlp(), execv(), execvp(), and execvpe().
 * Why do you think there are so many variants of the same basic call?
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Error: fork failed.\n");
        exit(1);
    }
    else if (rc == 0) {
        /* Child process */
        char *args[] = {"/bin/ls", NULL};
        execve("/bin/ls", args, NULL);
    }

    return 0;
}
