#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *words[100],*argx[3];
int pointer = 0;
char *myline;
size_t bufsize = 50;

char getWords(char *str,char *toker);

void methods(char ** envp);

void newArgs(char a[],char b[],char c[]);


int main(int argc, char **argv,char ** envp){
    
    int i;

    while(1) {
	pointer = 0;
	memset(&words, 0, sizeof(words));
	
	printf("myshell>> ");

	getline(&myline, &bufsize, stdin);

	getWords(myline,"&");

	if(words[1] == NULL && words[0] != NULL){
		pointer = 1;

		getWords(words[0]," \t\r\n\a");
	
		if(strcmp(words[0],"exit")==0){ 
		 pointer = 2;
		 break;
		}
		else if(strcmp(words[0],"clear")==0){
		 pointer = 2;
	 	 system("clear");
		}
		else if(strcmp(words[0],"cat")==0){
		 int j,pointer = 2;;
		 printf("cat : ");
			for(j = 1; words[j] != NULL; j++){
	 	 	printf("%s ",words[j]);
			}
		 printf("\n");
		}
		else if(pointer != 2){
		methods(envp);		
		}		

   	 }

	else if (words[1] != NULL && pointer != 1){ 


		char *komut2 = words[1];

		getWords(words[0]," \t\r\n\a ");

		methods(envp);		
	
		getWords(komut2," \t\r\n\a ");

		methods(envp);
	
	}

    }
	
    return 0;
}

void newArgs(char a[],char b[],char c[]){
	argx[0] = a,argx[1] = b,argx[2] = c;
}

char getWords(char *str,char *toker){
  char *word; 
  int i; 

  word = strtok (str,toker);

  for(i = 0; 1 ; i++){
	if(word == NULL){ 
	   break;
	}
	words[i] = word;
      	word = strtok (NULL, toker);
  }

}

void methods(char ** envp){
	int i,pid,pointer=0;
		
		if(strcmp(words[0],"rakam")==0) {
			pointer = 1;
		}

		pid = fork();

		if(pid==0){
			if(strcmp(words[0],"rakam")==0){
				newArgs(words[1],NULL,NULL);
				i = execv("rakam", argx); 
			}
			else if(strcmp(words[0],"mul")==0){
			   newArgs(words[1],words[2],NULL);
	 		   i = execv("mul", argx);
			}
			else if(strcmp(words[0],"div")==0){
			   newArgs(words[1],words[2],NULL);
	 		   i = execve("div", argx,envp);
			}
			else
		 	  printf("Hatalı Komut Girişi !\n");
		}
		else{
			if(pointer == 0 )		   
			   wait(&i);
		}
	
}






