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
    //FILE *fptr = fopen("database", "w"); //dosya olusturmak
	printf("size amk %d \n",atoi(argv[0]));
    for (i=1; i<atoi(argv[0]); i++)//dizini 0 elemneni dizini bouytu demek   
    { 
        printf("%d\n",atoi(argv[i])); // dosya yazdiriyor
    } 
    //fclose(fptr); 

   FILE *out = fopen("database", "a");  
   if (out==NULL) {
       FILE *fptr = fopen("database", "w"); //dosya olusturmak
   }
  for (i=1; i<atoi(argv[0]); i++)//dizini 0 elemneni dizini bouytu demek   
    { 
        fprintf(out,"%d\n",atoi(argv[i])); // dosya yazdiriyor
    }

    fclose(out);  
  
	return 0;
}
