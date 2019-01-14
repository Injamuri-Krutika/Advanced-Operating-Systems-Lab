/*Part II : Program 5 (1)
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

int main() {
    int fd;
    FILE *p = fopen("input", "r");
    char temp[1024];
    fscanf(p, "%s", temp);
    char *myfifo = "fifo";
    mkfifo(myfifo, 0666);
    fd = open(myfifo, O_WRONLY);
    write(fd, temp, sizeof(temp));
    close(fd);
    fclose(p);
    return 0;
}
