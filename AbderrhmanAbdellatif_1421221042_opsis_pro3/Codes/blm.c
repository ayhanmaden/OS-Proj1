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
#include <math.h>
pthread_mutex_t locktopla;
pthread_mutex_t lockkare;
int toplam;
int ikare;
int sum;
int number;
    void *topla()//$topla thread
{
	int i=1;
	for(i=1; i<=100; i++)
	{
		pthread_mutex_lock(&locktopla);
		toplam+=ikare;
		printf("toplam = %d \n",toplam);
        sleep(2);
		pthread_mutex_unlock(&lockkare);
	}
}

void *kare() //$kareal thread
{
	int i=1;
	for(i=1; i<=100; i++)
	{
		pthread_mutex_lock(&lockkare);		
		ikare=i*i; sum = 0;
     number = 0;
		//printf("kare = %d \n",ikare);
        sleep(2);
		pthread_mutex_unlock(&locktopla);
	}
}

int main(){	
	pthread_mutex_init(&locktopla, NULL);
	pthread_mutex_init(&lockkare, NULL);
	pthread_mutex_lock(&locktopla);

	pthread_t toplathread;
	pthread_t karethread;
	toplam=0;
	ikare=0;
	void* status;
    pthread_create(&toplathread,NULL,topla,NULL);
    pthread_create(&karethread,NULL,kare,NULL);
	pthread_join(toplathread,&status);
	pthread_join(karethread,&status);
	pthread_mutex_destroy(&lockkare); //olmasa olabilir
	pthread_mutex_destroy(&locktopla); // olmasa olabilir
	return 0;
}