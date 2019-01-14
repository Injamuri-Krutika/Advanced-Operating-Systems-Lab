/*Two process process P1 and process P2. For this you need to write two programs that run
on two diffrent terminal on your system. The process P1 should capture the interrupt i.e.
Ctrl+C from the keyboard you typed and send the interrupt signal to the process P2. When
process P2 receives the signal it shoud display it along with the process id of the sender process
(since there may be many sender processes, so to check which process sends the signal we
need to display the process ID’s ). As many times you type the Ctrl+C from the sender
process terminal the receiver process P2 should display it .
• All signals types are defined in signal.h header file.
• For this program you may use sigaction() function or signal() function.
• You can use the techniques used for inter process communications i.e. message queue
or shared memory or pipes etc.*/


#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h> 
#define SHM_SIZE 64

static void handler(int signum)
{
	printf("Inside Halndler function\n");
	int shmid;
	char * shm=(char *)malloc(sizeof(char)*SHM_SIZE);
	key_t key=5678;
	if((shmid=shmget(key,SHM_SIZE,IPC_CREAT|666))==-1){
		perror("shmget error");
		exit(1);
	}
	if((shm=shmat(shmid,NULL,0))==(char *)-1){
		perror("shmat error");
		exit(1);
	}
	//memset(shm,'\0',SHM_SIZE);
	sleep(1);
	sprintf(shm, "%d", getpid());
	printf("%s\n",shm);
}



int main()
{
	struct sigaction sa;
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART; /* Restart functions if interrupted by handler */

	if (sigaction(SIGINT, &sa, NULL) == -1){
		perror("Error in  sigaction function");
	}

	while(1);
}
