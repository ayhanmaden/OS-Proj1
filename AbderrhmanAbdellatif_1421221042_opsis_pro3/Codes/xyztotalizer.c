#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
pthread_mutex_t x_value;
pthread_mutex_t y_value; 
pthread_mutex_t z_value;
pthread_t x_thread;
pthread_t y_thread;
pthread_t z_thread;
int readnumber(char character, int line); //gelen thread bu fonkyorsun icine yoluyorum 
char * myfifo = "/tmp/myfifo";//adresi pipe yapıyoruz 0666 rwx-rwx-rwx >0-110-110-110
int cnt=1,xcount,ycount,zcount,sum=0;   //gelen degerleri 
int linenum=0;
int readcount;  //Program “readcount” kadar sayıyı okuyabilir
int npipefd;//named pipe adresi
void *x() //x deger ve thread  icin 
{
    while(linenum <= readcount){
    pthread_mutex_lock(&x_value);
    
        printf(" x thread \n");
        readnumber('x',linenum); 
        printf("[%d] x linenum \n",linenum);
    
    pthread_mutex_unlock(&y_value);
}
}

void *y()// y deger ve thread  icin
{
    while(linenum <= readcount){
        pthread_mutex_lock(&y_value);  
        printf(" y thread \n ");
        readnumber('y',linenum);
        printf("[%d] y linenum \n",linenum);
    pthread_mutex_unlock(&z_value);
}
}
void *z() //z deger ve thread  icin
{
    while(linenum <= readcount){
    
    pthread_mutex_lock(&z_value);
 
             printf("z thread \n");
             readnumber('z',linenum);
             printf("[%d] z linenum \n",linenum);
        
    pthread_mutex_unlock(&x_value);
}
}





int main(){
     printf(" how many time do you need  ");
     scanf("%d",&readcount); //kac kere okuyacagini yazdir kullanci 
     mkfifo(myfifo, 0666);

    pthread_mutex_init(&x_value, NULL);
    pthread_mutex_init(&y_value, NULL);
    pthread_mutex_init(&z_value, NULL); 
    
    pthread_mutex_lock(&y_value); 
    pthread_mutex_lock(&z_value); 
 

    void* status;

    pthread_create(&x_thread,NULL,x,NULL);
    pthread_create(&y_thread,NULL,y,NULL);
    pthread_create(&z_thread,NULL,z,NULL);

    pthread_join(x_thread,&status);
    pthread_join(y_thread,&status);
    pthread_join(z_thread,&status);


    return 0;
}

int readnumber(char character, int line){

         if(character=='x'){ // eger gelen karakter x ise okuyoru 
        
         npipefd= open(myfifo, O_WRONLY);
         write(npipefd,&line,sizeof(int)); //line  gonderiyor 
         printf(" line is sending %d\n",line);
         close(npipefd);



          npipefd=open(myfifo,O_RDONLY);//gelen sayi okuyor 
          read(npipefd,&xcount,sizeof(int)); // xcount atiyor 
          printf(" x value :%d ",xcount);
          puts("\n");
          close(npipefd);
        }

        
        if(character=='y'){ // eger gelen karakter x ise okuyoru 
        
         npipefd= open(myfifo, O_WRONLY);
         write(npipefd,&line,sizeof(int)); //line  gonderiyor 
         printf(" line is sending %d\n",line);
         close(npipefd);

          npipefd=open(myfifo,O_RDONLY);
          read(npipefd,&ycount,sizeof(int));//gelen sayi okuyor  dizden okuyor
          printf(" y value :%d ",ycount);
          puts("\n");
          close(npipefd);
        
        }
        if(character=='z'){
         npipefd= open(myfifo, O_WRONLY);
         write(npipefd,&line,sizeof(int));
         printf(" line is sending %d\n",line);
         close(npipefd);
       

         npipefd=open(myfifo,O_RDONLY);
          read(npipefd,&zcount,sizeof(int));
          printf(" z value :%d ",zcount);
          puts("\n");
          close(npipefd);
         
        }
        if (cnt==3) //burada eger ucten daha fazla ise bu true olyoru toplma icin
        {   
           sum=xcount+ycount+zcount; //gelen sayilar topluyorum
           printf(" sum of x value  ,y value , z value : %d + %d + %d = %d",xcount,ycount,zcount,sum);
           puts("\n ----------------------------------------------------------------\n ");
           xcount=0;
           ycount=0;//sifirliyorum  bir daha girmesi icin  
           zcount=0;
           cnt=0;
        }
    
   sleep(2);
   linenum++;//line burada atiyorum  cunku girilen sayi'a kadar 
   cnt++; // counter burda atiyorum  cunku toplam istiyorum her uc defe
}



