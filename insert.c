#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int i; 
    //open file sample.txt in write mode 
    FILE *fptr = fopen("database", "w"); 
    for (i=1; i<atoi(argv[0]); i++) 
    { 
        fprintf(fptr,"%d\n",atoi(argv[i])); 
    } 
    fclose(fptr); 
	return 0;
}
