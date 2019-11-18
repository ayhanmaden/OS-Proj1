#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
	int a = atoi(argv[0]); 
        int b = atoi(argv[1]); 
	int c = (a * b);
        printf("\n  %d  x  %d = %d \n",a,b,c);
	
	return 0;
}

