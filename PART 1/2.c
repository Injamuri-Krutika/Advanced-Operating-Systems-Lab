/*Write a simple C program that creates a process using the fork() call. Use the getpid() and
getppid() calls to print the child and parent id in created child process, and return value of fork call
in parent process
*/


#include<stdio.h>
#include <unistd.h>

void childProcess(){
	printf("Inside Child Process.\nProcess id is :: %d and Parent process id is :: %d \n",getpid(),getppid());
}

void parentProcess(){
	printf("Inside Parent Process.\nProcess id is :: %d\n",getpid());
}

int main(){
int p=fork();
if(p==0){
	childProcess();
}else{
	parentProcess();
}
return 0;
}

