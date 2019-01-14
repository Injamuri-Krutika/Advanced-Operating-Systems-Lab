/*Part II : Program 4
Program that creates two processes, a parent and a child where the child is
created via the fork() system call. The parent reads the content of a le and
sends them to child via Interprocess communication (IPC).The child receives the
data send by the parent and write them to another le. Hints: You can use any one
of the IPC mechanism like UNIX/LINUX pipes, Shared memory or message queue .
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    pid_t cpid;
    char buffer[1024];
    FILE *p = fopen("input", "r");
    FILE *q = fopen("output", "w");
    char string[1024];
    fscanf(p, "%s", string);
    pipe(pipefd);
    cpid = fork();
    if (cpid == 0) {
        close(pipefd[1]);
        while (read(pipefd[0], buffer, 1024) > 0)
            ;
        fprintf(q, "%s", buffer);
        close(pipefd[0]);
    } else {
        close(pipefd[0]);
        write(pipefd[1], string, strlen(string));
        close(pipefd[1]);
        wait(NULL);
    }
    return 0;
}

/*
 * $./a.out
 * Creates a file output.txt that the child uses to write the information its
 * has read, from it's parent.
 */
