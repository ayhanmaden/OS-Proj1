#include <fcntl.h>
#include <stdio.h>
#include <string.h>

main()
{
  int fd1, fd2;

  fd1 = open("file4", O_RDONLY | O_CREAT | O_TRUNC,0644);
  //perror("");
  fd2 = open("file4", O_RDONLY);
  //perror("");
  printf("fd1: %d\n",fd1);
  printf("fd2: %d\n",fd2);

  close(fd1);
 // close(fd2);

   fd1 = open("file4", O_RDONLY);
   printf("fd1: %d\n",fd1);
   printf("fd2: %d\n",fd2);
   close(fd1);
}
