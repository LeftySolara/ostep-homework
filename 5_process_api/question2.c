/* OSTEP Homework
 * Chapter 5, Question 2
 *
 * Write a program that opens a file (with the open() system call) and then
 * calls fork() to create a new process. Can both the parent and child access
 * the file descriptor returned by open()? What happens when they are writing
 * to the file concurrently (i.e., at the same time)?
 */

#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int rc = fork();
    int fd = open("example.txt", O_WRONLY | O_CREAT, S_IRWXU);

    if (fd == -1) {
        int error = errno;
        fprintf(stderr, "Error opening file.\n");
        exit(error);
    }

    if (rc < 0) {
        fprintf(stderr, "Error: fork failed.\n");
        exit(1);
    }
    else if (rc == 0) {
        /* Child process */
        ssize_t write_rc = write(fd, "Child\n", 6);
        if (write_rc == -1) {
            fprintf(stderr, "Error writing from child process.\n");
            exit(2);
        }
    }
    else {
        /* Parent process */
        ssize_t write_rc = write(fd, "Parent\n", 7);
        if (write_rc == -1) {
            fprintf(stderr, "Error writing from parent process\n");
            exit(3);
        }
    }
    close(fd);

    return 0;
}
