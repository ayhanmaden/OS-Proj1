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
int main(int argc, char *argv[])
{
    FILE *fptr1, *fptr2;
    int size = 0, c = 0, i = 0;
    char str[MAX];
    // make a file txt
    char newln[MAX], temp[] = "temp.txt";
    static const char fname[] = "data.txt";
    int forkdurum = 0;
    int pipe_p[2];
    // make a pipe 
    if (pipe(pipe_p) < 0)
    {
        printf("can not create  a pipe");
    }
    // to make array of pipe 
    pipe_p[0] = atoi(argv[0]);
    pipe_p[1] = atoi(argv[1]);
    fptr1 = fopen(fname, "r");
    fseek(fptr1, 0, SEEK_END);
    size = ftell(fptr1); // if file is empty or not
    if (0 == size)
    {
        int i[10];
        i[1] = -9;
        write(pipe_p[1], &i[0], sizeof(int));
        sleep(5);
    }
    else
    {
        // size of line
        FILE *myFile;
        myFile = fopen("data.txt", "r");
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
        int numberArray[lines + 1]; // array
        int i = 1;
        static const char filename[] = "data.txt";
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
        // open file 
        fptr2 = fopen(temp, "w");
        strcpy(newln, "");
        while (!feof(fptr1))
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
        }

        fclose(fptr1);// close file 
        fclose(fptr2); //close file 
        remove(fname);// remove files
        rename(temp, fname);// rename file 
        close(pipe_p[0]);
        numberArray[0] = lines + 1; // first index 
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