/*Write a simple C program to create a process using the exec() call. What is the difference
between a fork() and an exec() call*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{

        char *args[]={"./process2",NULL};
        execvp(args[0],args);
        printf("Process 1 completed\n");
     
    return 0;
}
