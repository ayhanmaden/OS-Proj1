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
#define MAX 256
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
    FILE *fptr1, *fptr2;
    int size = 0, c = 0, i = 0;
    char str[MAX];
    char newln[MAX], temp[] = "temp.txt";
    static const char fname[] = "test.txt";
    char *newargv[3];
    int forkdurum = 0;
    int pipe_p[2];
    if (pipe(pipe_p) < 0)
        printf("can not create  a pipe");

    while (1)
    {
        fptr1 = fopen(fname, "r");
        fseek(fptr1, 0, SEEK_END);
        size = ftell(fptr1); // if file is empty or not
        if (0 == size)
        {
            printf("file is empty\n");
            printf("lines file is : 0. \n");
            sleep(10);
        }
        else
        {
            if (!fptr1)
            {
                printf("Unable to open the input file!!\n");
                return 0;
            }
            // size of line
            FILE *myFile;
            myFile = fopen("test.txt", "r");
            int lines = 0;
            char ch = 0;

            while (!feof(myFile))
            {
                ch = fgetc(myFile);
                if (ch == '\n')
                {
                    lines++;
                }
            }
            printf("lines file %d\n", lines);
            int numberArray[lines][4]; // array
            int i = 0;
            char *numbers;
            static const char filename[] = "test.txt";
            FILE *file = fopen(filename, "r");
            if (file != NULL)
            {
                char line[7];                                   /* or other suitable maximum line size */
                while (fgets(line, sizeof(line), file) != NULL) /* read a line */
                {
                    fputs(line, file);
                    numberArray[i][4] = atoi(line); /* write to array  */
                    i++;
                }
                fclose(file);
            }

            fptr2 = fopen(temp, "w");
            if (!fptr2)
            {
                printf("Unable to open a temporary file to write!!\n");
                fclose(fptr1);
                return 0;
            }
            /* get the new line from the user */
            strcpy(newln, "");
            /* get the line number to delete the specific line */
            // copy all contents to the temporary file other except specific line
            while (!feof(fptr1))
            {
                strcpy(str, "\0");
                fgets(str, MAX, fptr1);
            }
            fclose(fptr1);
            fclose(fptr2);
            remove(fname);
            rename(temp, fname);
            printf("successfully..!! \n");
            char str[15];
            sprintf(str, "%d", lines);
            newargv[0] = "convert(pipe_p[0])";
            newargv[1] = "convert(pipe_p[1])";
            newargv[2] = str;
            newargv[3] = NULL;
            if ((forkdurum = fork()) < 0)
            {
                printf("can't create  a fork ");
            }
            else if ((forkdurum = fork()) == 0)
            {
                c = execv("main", newargv);
            }
            else if (forkdurum > 0)
            {
                 close(pipe_p[0]);
                for (int i = 0; i < lines; i++)
                {
                    if (write(pipe_p[1], numberArray, sizeof(numberArray)) < 0) // write in pipe
                    {
                        printf("cant write in to pipe  ");
                    }
                    printf("write %d\n", numberArray[i][0]);
                }
                
                wait(&c);
            }
        }
        sleep(10);
    }
    return 0;
}
