/*Write a C/C++ program to fiind the number of processes (together with all process details)
running on the system using system calls. Additionally, you may use fork() system call to
create more processes*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
# include <sys/sysinfo.h>
#include <dirent.h>
#include <ctype.h>
int getNumOfProcs(){
	struct sysinfo si;
	return (sysinfo(&si) == 0) ? (int)si.procs : (int)-1;
}


int getNumOfProcsFromFolder(){
	DIR * proc=opendir("/proc");
	struct dirent * entry;
	int file_count=0;
	if(!proc){
		printf("Dir open Error");
		exit(0);
	}else{
		while ((entry = readdir(proc)) != NULL) {
		    if (isdigit(*entry->d_name)) { 
			 file_count++;
		    }
		}
	}
	return 	file_count;
}

int getAvgMemoryUsed(){
	DIR * proc=opendir("/proc");
	struct dirent * entry;
	struct dirent * subEntry;
	int file_count=0;
	if(!proc){
		printf("Dir open Error");
		exit(0);
	}else{
		
		
		char * lineBuff=(char *)malloc(sizeof(char)*1024);
		while ((entry = readdir(proc)) != NULL) {

		//	while ((subEntry = readdir(entry)) != NULL) {

		    if (!strcmp(entry->d_name,"meminfo")) { 
			printf("Inside meminfo %s\n",entry->d_name);
			FILE * fp=fopen("/proc/meminfo","r");	
			if(!fp){
				printf("File not opening\n");
			}
			printf("Hi");
			while(fgets(lineBuff,1024,fp)!=NULL){
				printf("%s",lineBuff);
				if(strstr(sent, word) != NULL) {
    				/* ... */
}
			}
			
		    }



		}
	}
	return 	file_count;
}

int main(){
/*for(int i=0;i<4;i++){
	fork();
}*/
//printf("Num of procs : %d\n",getNumOfProcs());
//printf("Num of procs from procs folder: %d\n",getNumOfProcsFromFolder());
getAvgMemoryUsed();
return 0;
}


