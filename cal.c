#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	for (int i=0; i<3; i++) 
    { 
        printf("[%s\n]",argv[i]); 
    } 
    FILE* ptr = fopen("database","r"); 
    /* Assuming that abc.txt has content in below 
       format 
       1
       2
       3
       4
       5
        */
    char* buf[100];
    int cut=0,sum=0; 
    while (fscanf(ptr,"%d",buf)==1){
        if(cut==atoi(argv[1]) || cut==atoi(argv[2]) ){
          sum=sum+atoi(buf);
        }
        cut++;
        printf("amk => %d \n", cut); 

    } 
	return 0;
}
