

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIMIT 100
int main()
{
	// insert , calculate , readall , clear , exit 
	char str[MAX_LIMIT];
	fgets(str, MAX_LIMIT, stdin);
	printf("%s", str);
	char* str2 = (char*)malloc(sizeof(char) * MAX_LIMIT);
	strcpy(str2, str);
	char delim[] = " ";
	int  number[10], i = 0, size = 0;
	char* ptr = strtok(str2, delim);

	while (ptr != NULL)
	{
		printf("%s\n", ptr);
		if (size >= 2) {
			number[i] = atoi(ptr);
			i++;
		}
		size++;
		ptr = strtok(NULL, delim);
	}

	for (int k = 0; k < i; k++) {
		printf(" ===> %d \n ", number[k]);
	}

	return 0;
}
