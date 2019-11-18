#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
	int sayi = atoi(argv[0]); 
	int bolen = atoi(argv[1]);
	double sonuc =((double)sayi / (double)bolen); 
	printf("\n  %d  /  %d = %f \n", sayi, bolen, sonuc);
	return 0;
}

