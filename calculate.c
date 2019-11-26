#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *myFile;
    myFile = fopen("database", "r");
    int numberArray[atoi(argv[3]) - 1];
    int i;
    for (i = 0; i < atoi(argv[3]) - 1; i++)
    {
        fscanf(myFile, "%d", &numberArray[i]);
    }

    if (strcmp(argv[0], "-s") == 0)
    {  
        int sum=(numberArray[atoi(argv[1])]+numberArray[atoi(argv[2])]);
        puts(" ");
        printf("sum ==> %d + %d = %d",
        numberArray[atoi(argv[1])-1],
        numberArray[atoi(argv[2])-1],
        sum);
    }
    else if (strcmp(argv[0], "-r") == 0)
    {
        int sum=0;
        for (i = atoi(argv[1]); i <atoi(argv[2]); i++)
        {
            printf("Number is: %d\n\n", numberArray[i]);
            sum = sum+ numberArray[i];
        }
        puts(" ");
        printf("sum %d ",sum);
    }
}
