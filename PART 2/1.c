/*(Implement using C/ C++ program) : Given a set of processes (P1, P2, ..., Pn) and resources
(R1, R2, ..., Rn), at any instant, the set of requests (Pi to Rj) and the set of assignments (Ri
to Pj) are given:
(a) Find out that no single resource is assigned to multiple processes.
(b) Find out that the processes is not making repeated requests for the same resource.*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int main(){
int requests[5][5]={{1,0,1,0,1},
		{0,0,1,1,1},
		{0,1,0,1,0},
		{1,0,0,0,1},
		{0,5,1,1,0}};

int assigned[5][5]={{5,0,0,0,0},
		{0,3,0,0,0},
		{0,3,0,0,0},
		{0,0,7,0,0},
		{0,0,0,0,5}};

bool isValid=true;
for(int i=0;i<5;i++){
	int count=0;
	for(int j=0;j<5;j++){
		if(assigned[i][j]!=0){
			count++;
		}
		if(count>1){
			isValid=false;
			break;
		}
	}
	if(!isValid){
		printf("Single Resource is assigned to multiple processes\n");
		break;
	}
}

if(isValid){
	printf("No single resource is assigned to multiple processes\n");
}


for(int i=0;i<5;i++){
	int count=0;
	for(int j=0;j<5;j++){
		if(requests[i][j]>1){
			isValid=false;
			break;
		}
	}
	if(!isValid){
		printf("Process is making repeated requests for the same resource\n");
		break;
	}
}

if(isValid){
	printf("Processes are not making repeated requests for the same resource\n");
}

return 0;
}
