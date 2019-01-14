/*Part II : Program 5 (2)
Programs that creates two processes ( process1 and process2 ). The process 1
reads the content of a le and sends them to process 2 via Interprocess communi-
cation (IPC).The receiver process ( process 2) receives the data send by the
sender process (process 1) and write them to another le. Hints: You can use any
one of the IPC mechanism like UNIX/LINUX pipes, Shared memory or message queue .
*/

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX_BUF 1024

int main(void) {
    int fd;
    FILE *p = fopen("output", "w");
    char *myfifo = "fifo";
    char buf[MAX_BUF];
    fd = open(myfifo, O_RDONLY);
    read(fd, buf, MAX_BUF);
    fprintf(p, "%s\n", buf);
    close(fd);
    fclose(p);
    return 0;
}
