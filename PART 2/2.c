/*
This program based on two process( parent and child ) communication using
signals.
Description:The parent send messages or signals to child using the pid and kill(). The child
picks up these signals with signal() function and calls appropriate functions to handle it.
• All signals types are defined in signal.h header file.
• The signal that you require in your program are SIGINT(Ctrl+C) , SIGQUIT(Ctrl+D)
• The communication between perent and child processes is done using kill() and signal(),
fork() system call.
*/



#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <signal.h>


void sigKill(){
	
	printf("Inside SIGKILL : %d \n",getpid());
}

void sigQuit(){
	
	printf("Inside SIGQUIT : %d\n",getpid());
}


void sigInt(){
	
	printf("Inside SIGINT : %d\n",getpid());
}

int main(){
	
	int id=fork();
	if(id==0){
		printf("Child Process :: %d\n",getpid());
		signal(SIGINT, sigInt);
		signal(SIGQUIT, sigQuit);
		for(;;); 
	}else{	
		printf("Parent Process :: %d, child Process :: %d \n",getpid(),id);
		sleep(3);
		//for(;;); 
		//signal(SIGINT, SIG_DFL);	
		//signal(SIGQUIT, SIG_DFL);
		kill(id, SIGQUIT);
		sleep(3);
		kill(id, SIGINT);
		sleep(3);
	}

return 0;
}
