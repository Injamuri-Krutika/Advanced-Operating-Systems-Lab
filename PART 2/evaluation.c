#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

int main() 
{ 

	int fd1[2];
	pid_t p; 
	int inputSize=0;
	char concat_str[100]; 

	if (pipe(fd1)==-1) 
	{ 
		fprintf(stderr, "Pipe Failed" ); 
		return 1; 
	} 
	p = fork(); 

	if (p < 0) 
	{ 
		fprintf(stderr, "fork Failed" ); 
		return 1; 
	} 
	else if (p > 0) 
	{ 
		close(fd1[0]); 

		FILE *fp=fopen("input.txt","r");
	
		if(!fp){
		perror("File Error");
		exit(1);
		}
		int roll,marks,val,count=0;
		float avg=0.0;
		
		while(fscanf(fp,"%d",&val)!=EOF){
			count++;
		}
		rewind(fp);
		inputSize=count/2;
		int rollArr[inputSize],marksArray[inputSize],i=0;
		while(fscanf(fp,"%d",&val)!=EOF){
			if((count--)%2==0){
				rollArr[i]=val;
			}else{
				marksArray[i++]=val;
				avg+=val;
			}
		}
		avg/=inputSize;
		printf("Average=%f",avg);
		for(int k=0;k<inputSize;k++){

			printf("%d , %d \n",rollArr[k],marksArray[k]);
		}
		
		for(int k=0;k<inputSize;k++){
			if(marksArray[k]<avg){
				sprintf(concat_str, "Roll : %d, Marks : %d, Below Average", rollArr[k],marksArray[k]);
				printf("%s\n",concat_str);
			}else if(marksArray[k]==avg){
				sprintf(concat_str, "Roll : %d, Marks : %d, Equal Average", rollArr[k],marksArray[k]);
				printf("%s\n",concat_str);
			}else{
				sprintf(concat_str, "Roll : %d, Marks : %d, Above Average", rollArr[k],marksArray[k]);
				printf("%s\n",concat_str);
			}
			write(fd1[1], concat_str, strlen(concat_str)+1); 
			sleep(1);
		
		}
		write(fd1[1], "Break", strlen(concat_str)+1); 
		close(fd1[1]); 

	}  
	else
	{ 
		printf("Inside child\n");
		close(fd1[1]); 
		FILE * fp =fopen("output.txt","w");
		while(1){
			read(fd1[0], concat_str, 100);
			printf("%s\n",concat_str);
			
			if(strcmp(concat_str,"Break")==0)
				break;
			fprintf(fp,"%s\n",concat_str);
		}
		close(fd1[0]);
		exit(0); 
	} 
} 

/*
Input Values:
1 10
2 20
3 30
4 40
5 50
6 60
7 70
8 80
9 90
10 100

Output Values:
Roll : 1, Marks : 10, Below Average
Roll : 2, Marks : 20, Below Average
Roll : 3, Marks : 30, Below Average
Roll : 4, Marks : 40, Below Average
Roll : 5, Marks : 50, Below Average
Roll : 6, Marks : 60, Above Average
Roll : 7, Marks : 70, Above Average
Roll : 8, Marks : 80, Above Average
Roll : 9, Marks : 90, Above Average
Roll : 10, Marks : 100, Above Average
*/
