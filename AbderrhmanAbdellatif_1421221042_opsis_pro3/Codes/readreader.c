#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
void readFile();
int sayilar[20];
int npipefd;
int size = 0;
int main()
{
  char *myfifo = "/tmp/myfifo";
  readFile();
  mkfifo(myfifo, 0666);
  int value0fxyz = 0;
  while (1)
  {

    npipefd = open(myfifo, O_RDONLY); // gelen satir okuoyrum
    read(npipefd, &value0fxyz, sizeof(int));
    printf(" line :%d ", value0fxyz);
    puts("\n");
    close(npipefd);

    size_t n = sizeof(sayilar) / sizeof(int); //array sizen aliyoum
    if (value0fxyz > n)
    {
      printf(" \n there is no number \n ");
      break;
    }
    else
    { //eger sayi varsa thread gidiyor yoksa break yapip gidiyor thread giremiyor
      npipefd = open(myfifo, O_WRONLY);
      write(npipefd, &sayilar[value0fxyz], sizeof(int)); //arraydeki line num index gibi arraydeki  valuesunu aliyorum
      printf(" value is sending %d\n", sayilar[value0fxyz]);
      close(npipefd);
    }
  }

  return 0;
}

void readFile()
{
  int MAXCHAR = 10;
  FILE *dosya = fopen("./numbers.txt", "r"); //text dosyasini aciyorum
  char sayi[MAXCHAR];
  int i = 0;
  if (NULL != dosya) //eger oyle bir dosya yok ise cikyorum
  {
    
      while (fgets(sayi, MAXCHAR, dosya) != NULL)
      {
        sayilar[i] = atoi(sayi); //gelen  file deki  degeri okuyorum  ve arrayya atiyorum
        fprintf(dosya,"%s",NULL);
        i++;
      }
      fclose(dosya);
      int j;

      for (j = 0; j < 18; j++)
      {
        printf("%d. number = %d \n", j, sayilar[j]);
      }
    
  }
}
