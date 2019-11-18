#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
  int fd;
  const char *buffer="ayhan arslan \n";

  fd = open("database", O_WRONLY | O_CREAT | O_APPEND,0644);
  write(fd,buffer,strlen(buffer));

  close(fd);
  
  return 0;
}
