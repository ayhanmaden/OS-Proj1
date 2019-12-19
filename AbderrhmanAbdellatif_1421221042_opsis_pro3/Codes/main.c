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
#include <string.h>
char *convert(int number)
{
    int count = 0;
    int numbertmp = number;
    while (numbertmp > 0)
    {
        int digit = numbertmp % 10;
        numbertmp /= 10;
        count++;
    }
    char *value = (char *)calloc(count, sizeof(unsigned char));
    numbertmp = number;
    count--;
    while (numbertmp > 0)
    {
        int digit = numbertmp % 10;
        numbertmp /= 10;
        char x = (char)48 + digit;
        *(value + count) = x;
        count--;
    }

    return value;
}
int main()
{
    int pipefd[2];
    int pid;
    int i, line;
    char s[1000];
    int c;
    int numberArray[10];

    if (pipe(pipefd) < 0)
    {
        perror("pipe");
        exit(1);
    }
    char *newargv[2];
    newargv[0] = convert(pipefd[0]);
    newargv[1] = convert(pipefd[1]);
    newargv[2] = NULL;
    pid = fork();

    if (pid == 0)
    {

        c = execv("reader", newargv);
        perror("");
        close(pipefd[1]);
    }
    else
    {

        wait(&c);
        printf("reading from pipe ...\n");
        read(pipefd[0], numberArray, sizeof(numberArray));
        for (int i = 0; i < 10; i++)
        {
            printf("read from pipe => %d\n", numberArray[i]);
        }
        
    }
    return 0;
}

