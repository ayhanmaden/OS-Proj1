#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 256
int main()
{
    FILE *fptr1, *fptr2;
    int size=0,i,sayilar[20];;
    char str[MAX];
    char newln[MAX], temp[] = "temp.txt";
    static const char fname[] = "test.txt";
    fptr1 = fopen(fname, "r");
    fseek(fptr1, 0, SEEK_END);
    size = ftell(fptr1);
    if (0 == size)
    {
      printf("file is empty\n");
    }
    else
    {
    if (!fptr1)
    {
        printf("Unable to open the input file!!\n");
        return 0;
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
        if (!feof(fptr1))
        {   
            fscanf(fptr1, "%d", &no);
            sayilar[i] = atoi(no); //gelen  file deki  degeri okuyorum  ve arrayya atiyorum
            i++;
            fprintf(fptr2, "%s", newln);
        }
    }
    for(int j=0;i<i;j++){
      printf("%d\n",i);
    }
    fclose(fptr1);
    fclose(fptr2);
    remove(fname);
    rename(temp, fname);
    printf("successfully..!! \n");
    }
    return 0;
}
