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
#define MAX 256
int strtoint(char *charnums)
{
    int number = 0;
    int index = 0;
    while (charnums[index])
    {
        if (('0' <= charnums[index]) && (charnums[index] <= '9'))
        {

            if (!number)
                number = ((int)charnums[index]) - 48;
            else
            {
                number = (number *= 10) + ((int)charnums[index] - 48);
            }
            index++;
        }
        else
        {
            number = -1;
            printf("\nGecersiz islem");
            break;
        }
    }
    return number;
}
int main(int argc, char *argv[])
{
    FILE *fptr1, *fptr2;
    int size = 0, c = 0, i = 0;
    char str[MAX];
    char newln[MAX], temp[] = "temp.txt";
    static const char fname[] = "test.txt";
    int forkdurum = 0;
    int pipe_p[2];
    if (pipe(pipe_p) < 0)
    {
        printf("can not create  a pipe");
    }
    pipe_p[0] = strtoint(argv[0]);
    pipe_p[1] = strtoint(argv[1]);
    fptr1 = fopen(fname, "r");
    fseek(fptr1, 0, SEEK_END);
    size = ftell(fptr1); // if file is empty or not
    if (0 == size)
    {
        printf("file is empty\n");
        int i[10];
        i[1] = -9;
        write(pipe_p[1], &i[0], sizeof(int));
        sleep(5);
    }
    else
    {
        // size of line
        FILE *myFile;
        myFile = fopen("test.txt", "r");
        int lines = 0;
        pipe_p[0] = strtoint(argv[0]);
        pipe_p[1] = strtoint(argv[1]);
        char ch = 0;
        while (!feof(myFile))
        {
            ch = fgetc(myFile);
            if (ch == '\n')
            {
                lines++;
            }
        }
        int numberArray[lines + 1]; // array
        int i = 1;
        static const char filename[] = "test.txt";
        FILE *file = fopen(filename, "r");
        if (file != NULL)
        {
            char line[7];                                   /* or other suitable maximum line size */
            while (fgets(line, sizeof(line), file) != NULL) /* read a line */
            {
                fputs(line, file);
                numberArray[i] = atoi(line); /* write to array  */
                i++;
            }
            fclose(file);
        }
        fptr2 = fopen(temp, "w");
        strcpy(newln, "");
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
        close(pipe_p[0]);
        numberArray[0] = lines + 1;
        for (int i = 0; i < lines + 2; i++)
        {
            if (write(pipe_p[1], &numberArray[i], sizeof(int)) < 0) // write in pipe
            {
                printf("cant write in to pipe  ");
            }
            if (i != 0)
            {
                printf("write in pipe %d\n", numberArray[i]);
            }
            sleep(2);
        }
    }
    return 0;
}