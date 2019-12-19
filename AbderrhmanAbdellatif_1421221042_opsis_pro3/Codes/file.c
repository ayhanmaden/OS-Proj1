#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 256
int main()
{
    FILE *fptr1, *fptr2;
    int size=0,i=0;
    char str[MAX];
    char newln[MAX], temp[] = "temp.txt";
    static const char fname[] = "test.txt";
    fptr1 = fopen(fname, "r");
    fseek(fptr1, 0, SEEK_END);
    size = ftell(fptr1);
    if (0 == size)
    {
      printf("file is empty\n");
      printf("lines file is : 0. \n");
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
    int numberArray[lines];
    int i=0;
    char *numbers;
    static const char filename[] = "test.txt";
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
    for(int j=0;j<lines;j++){
      printf(" %d \n",numberArray[j]);
    }
    fclose(fptr1);
    fclose(fptr2);
    remove(fname);
    rename(temp, fname);
    printf("successfully..!! \n");
    }
    return 0;
}
