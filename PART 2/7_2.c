/* Part II : Program 7 (2)
Producer/Consumer problem using shared memory and semaphores: Each pro-
ducer reads its input le one character at a time and writes it into a shared bu
er.The consumer consumes characters from this buer one at a time and writes
them into output les. The size of the buer is nite. Use semaphores for
synchronization between producer and consumer processes. There should be three
dierent les two input les for producer and one output le for consumer
*/

#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define SHMSZ 1

int main() {
    char *c, string[50];
    FILE *in = fopen("producer1.txt", "r");
    fscanf(in, "%s", string);
    int shmid;
    key_t key;
    char *shm, *s;
    key = 5678;
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    if ((shm = shmat(shmid, NULL, 0)) == (char *)-1) {
        perror("shmat");
        exit(1);
    }
    sem_t *empty = sem_open("EMPTY", O_CREAT, 0666, 1);
    sem_t *full = sem_open("FULL", O_CREAT, 0666, 0);
    sem_t *mutex = sem_open("MUTEX", O_CREAT, 0666, 1);
    s = shm;
    c = string;
    while (*c != '\0') {
        sem_wait(empty);
        sem_wait(mutex);
        printf("Producer 1 in CS\n");
        *s = *c++;
        sem_post(mutex);
        sem_post(full);
    }
    sem_unlink("EMPTY");
    sem_unlink("FULL");
    sem_unlink("MUTEX");
    return 0;
}
