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
    int numberArray[lines];
    int i;
    char *numbers;
    static const char filename[] = "database";
    FILE *file = fopen(filename, "r");
    if (file != NULL)
    {
        char line[3];                                   /* or other suitable maximum line size */
        while (fgets(line, sizeof(line), file) != NULL) /* read a line */
        {
            fputs(line,file);
            numberArray[i]=atoi(line); /* write to array  */
            i++;
        }
        fclose(file);
    }
    else
    {
        perror(filename); /* why didn't the file open? */
    }
    if (strcmp(argv[0], "-s") == 0)
    {
        int sum = (numberArray[atoi(argv[1])] + numberArray[atoi(argv[2])]);
        puts(" ");
        printf("sum ==> %d",sum);
    }
    else if (strcmp(argv[0], "-r") == 0)
    {
        int sum = 0, a = atoi(argv[1]), b = atoi(argv[2]);
        if (a < b)
        {
            for (i = atoi(argv[1]); i < (atoi(argv[2])) + 1; i++)
            {
                sum = sum + numberArray[i];
            }
            printf("sum  %d ", sum);
        }
        else 
        {

            for (i = atoi(argv[1]); i >= (atoi(argv[2])); i--)
            {
                sum = sum + numberArray[i];
            }
            printf("sum  %d ", sum);
        }
    }
}
