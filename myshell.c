#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAX_LIMIT 100

int main(){
 
   // insert , calaulate , readall , clear , exit
   
   char str[MAX_LIMIT]; // limit input 
   fgets(str,MAX_LIMIT,stdin); // input from user 
   char * str2=(char*)malloc(sizeof(char)* MAX_LIMIT); // char str2[MAX_LIMIT] 
   strcpy(str2,str); // string make cp
   char delim[]=" ";// splite 
   char * ptr=strtok(str2,delim);// string ptr[]=split(" "); 
   ptr=strtok(NULL,delim); // 
   //printf("%s\n",ptr);
    printf("hello");
   if((strcmp(ptr,"insert"))==0){
     printf("true");
   }
  
   return 0 ;
 

}
