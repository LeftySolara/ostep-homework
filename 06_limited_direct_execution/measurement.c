#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * @brief Measures the average time used by the read() system call.
 *
 * @param measurements The number of measurements to take.
 * @param iterations The number of read() calls to make per measurement.
 */
void measure_syscall_read(int measurements, int iterations)
{
    struct timeval start_time;
    struct timeval end_time;
    suseconds_t start_ms;
    suseconds_t end_ms;
    double avg_time;

    char *buf = malloc(sizeof(*buf));
    int fd = open("sample.txt", O_RDONLY);

    for (int measurement = 0; measurement < measurements; ++measurement) {
        gettimeofday(&start_time, NULL);
        for (int i = 0; i < iterations; ++i)
            read(fd, buf, 0);
        gettimeofday(&end_time, NULL);

        suseconds_t start_ms = (start_time.tv_sec * 1000) + start_time.tv_usec;
        suseconds_t end_ms = (end_time.tv_sec * 1000) + end_time.tv_usec;
        avg_time = ((double)end_ms - (double)start_ms) / (double)iterations;

        printf("Average system call measurement in milliseconds: %.8f\n", avg_time);
    }

    close(fd);
    free(buf);
}

int main (int argc, char **argv)
{
    measure_syscall_read(5, 100000);

    return 0;
}
