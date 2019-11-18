#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int n, i, temp = 0;
    n = atoi(argv[0]);
const char *numbers[10] = { "Sifir", "Bir", "Iki", "Uc", "Dort", "Bes",
			"Alti", "Yedi", "Sekiz", "Dokuz" };

    printf("%d >> %s \n",n,numbers[n]);
    return 0;
}
