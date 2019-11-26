#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIMIT 100
char *str3[MAX_LIMIT], *pozitif[100];
void inputword(char *input); // get word from user input;;
void mathods(int i);
void main(int argc, char **argv, char **envp)
{
	// insert , calculate , readall , clear , exit
	char str[MAX_LIMIT]; // limit input
	while (1)
	{
		printf("\naccountant>>");
		fgets(str, MAX_LIMIT, stdin); // input from user
		inputword(str);				  // full array
		if ((strcmp(str3[0], "insert")) == 0)
		{
			char k = 1;
			for (int i = 1; i < 100; i++) // negative numbers contorl
			{
				if (str3[i] != NULL)
				{
					pozitif[k] = str3[i];
					k++;
				}
			}
			char snum[2];
			sprintf(snum, "%d", k);
			pozitif[0] = snum;
			mathods(1);
		}
		else if ((strcmp(str3[0], "calculate")) == 0)
		{
			if ((strcmp(str3[1], "-r") == 0))
			{

				printf(" -r ");
			}
			else if ((strcmp(str3[1], "-s") == 0))
			{
				printf(" -s ");
			}
			else
			{
				printf("error");
			}
		}
		else if ((strcmp(str3[0], "readall\n")) == 0)
		{
			printf("readall cmd ");
		}
		else if ((strcmp(str3[0], "clear\n")) == 0)
		{
			system("cls");
		}
		else if ((strcmp(str3[0], "exit\n")) == 0)
		{
			exit(0);
		}
		else
		{
			printf("%s : command not found ", str);
		}
	}
}

void inputword(char *input)
{
	char *str2 = (char *)malloc(sizeof(char) * MAX_LIMIT); // char str2[MAX_LIMIT]
	strcpy(str2, input);								   // string make cp
	char delim[] = " ";									   // splite
	char *ptr = strtok(str2, delim);					   // string ptr[]=split(" ");
	for (int i = 0; 1; i++)
	{
		if (ptr == NULL)
		{
			break;
		}
		str3[i] = ptr;
		ptr = strtok(NULL, delim);
	}
}

void mathods(int flg)
{
	int pid = fork(), id;
	if (pid == 0)
	{
		if (flg == 1)
		{
			id = execv("insert", pozitif);
		}
	}
	else
	{
		wait(&id);
	}
}
