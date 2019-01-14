/*Write a program to find out the number of processes and their states, like CPU time, submission
time, memory size of the process etc. at any instant. Store the information in a table structure for
further processing
*/



#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_BUFF_SIZE 10000
int main()
{

char string1[MAX_BUFF_SIZE];
sprintf(string1,"top -b -n 1  > top.txt");
system(string1);
return 0;
}
