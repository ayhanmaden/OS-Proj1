/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "acount >> compile 5 2 45 6";
	int init_size = strlen(str);
	char delim[] = " ";
    int  number[10],i=0,size=0;
	char *ptr = strtok(str, delim);

	while(ptr != NULL)
	{
		printf("%s\n", ptr);
		if(size>=3){
		    number[i]=atoi(ptr);
		    i++;
		}
		size++;
		ptr = strtok(NULL, delim);
	}

    for(int k=0 ;k < i ; k++){
         printf(" ===> %d \n ",number[k]);   
    }

	return 0;
}