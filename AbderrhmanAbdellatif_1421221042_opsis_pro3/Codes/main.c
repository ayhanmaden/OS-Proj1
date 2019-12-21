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
#include <math.h>
pthread_mutex_t thread_reader_lock;
pthread_mutex_t thread_calculater_lock;
int sum = 0, array_size = 0, number = 0, d = 1, p = 0, m = 0;
;
int pipefd[2], num[100], numberArray_ilk[100];

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
void *reader() //$reader thread
{

    pthread_mutex_lock(&thread_reader_lock);
    number = numberArray_ilk[d];
    printf(" number %d\n", number);
    d++;
    pthread_mutex_unlock(&thread_calculater_lock);
}

void *calculater() //$kareal thread
{

    pthread_mutex_lock(&thread_calculater_lock);
    sum = sum + pow(number, 2);
    if (p == 0)
    {
        m = array_size;
        p++;
    }
    if (d > (m + 1))
    {
        p = 0;
        d = 1;
        for (int i = 0; i < 100; i++)
        {
            numberArray_ilk[i] = 0;
        }
    }
    printf("Toplam --> %d\n", sum);
    sleep(2);
    pthread_mutex_unlock(&thread_reader_lock);
}

int main()
{
    int pid;
    int i, line;
    char s[1000];
    int c;

    if (pipe(pipefd) < 0)
    {
        perror("pipe");
        exit(1);
    }
    while (1)
    {
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

            read(pipefd[0], numberArray_ilk, sizeof(numberArray_ilk));
            for (int i = 1; i < (numberArray_ilk[0] + 1); i++)
            {
                printf("read from pipe => %d\n", numberArray_ilk[i]);
                sleep(2);
            }
            array_size = numberArray_ilk[0];
        };

        pthread_mutex_init(&thread_reader_lock, NULL);
        pthread_mutex_init(&thread_calculater_lock, NULL);
        pthread_mutex_lock(&thread_calculater_lock);

        pthread_t thread_reader;
        pthread_t thread_calculater;

        void *status;
        pthread_create(&thread_reader, NULL, reader, NULL);
        pthread_create(&thread_calculater, NULL, calculater, NULL);
        pthread_join(thread_reader, &status);
        pthread_join(thread_calculater, &status);
    }
    return 0;
}
