	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define  MAX_LIMIT 100
	char* str3[MAX_LIMIT];
	void inputword(char* input);// get word from user input;;
	void instermathod(int p[],int i);
	void main() {
		// insert , calculate , readall , clear , exit
		char str[MAX_LIMIT]; // limit input
		while (1)
		{
			printf("\naccountant>>");
			fgets(str, MAX_LIMIT, stdin); // input from user 
			inputword(str);// full array 
			if ((strcmp(str3[0], "insert")) == 0) {
				int pozitif[100], k = 0;
				for (int i = 1; i <100; i++)// negative numbers contorl
				{
					if (str3[i] != NULL)  {
						pozitif[k] = atoi(str3[i]);
						k++;
					}
				}
				instermathod(pozitif,k);
			}
			else if ((strcmp(str3[0], "calculate")) == 0) {
				if ((strcmp(str3[1], "-r")==0)) {

					printf(" -r ");
				}
				else if((strcmp(str3[1], "-s") == 0))
				{
					printf(" -s ");
				}
				else {
					printf("error");
				}
			}
			else if ((strcmp(str3[0], "readall\n")) == 0) {
				printf("readall cmd ");
			}
			else if ((strcmp(str3[0], "clear\n")) == 0) {
				system("cls");
			}
			else if ((strcmp(str3[0], "exit\n")) == 0) {
				exit(0);
			}
			else { printf("%s : command not found ",str); }
		
		}
	}

	void inputword(char* input)
	{
		char* str2 = (char*)malloc(sizeof(char) * MAX_LIMIT); // char str2[MAX_LIMIT]
		strcpy(str2, input); // string make cp
		char delim[] = " ";// splite 
		char* ptr = strtok(str2, delim);// string ptr[]=split(" "); 
		for (int i = 0;1; i++)
		{
			if (ptr==NULL) {
				break;
			}
			str3[i] = ptr;
			ptr = strtok(NULL, delim);
		}
	
	}

	void instermathod(int p[],int size)
	{
		for (int i = 0; i <size; i++)
		{
			printf("%d   ",p[i]);

		}
	}
