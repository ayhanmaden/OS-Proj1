#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{

    int pipe_p[2];
    int i;
    int lines = atoi(argv[2]);
    int numberArray[lines][4];
    printf("lines : %d \n",lines);
    if (pipe(pipe_p) < 0)
    {
        perror("pipe");
        exit(1);
    }
    if (read(pipe_p[0],numberArray, sizeof(numberArray)) < 0)
    {
        printf("C: Can't read ");
    }
    
    for (int j = 0; j < lines; j++)
            {
                printf(" aliyor %d \n", numberArray[j][4]);
            }

    return 0;
}