#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>

main()
{
  int stat;
  int pid=fork();
  if(pid<0)
    {
      perror("main");
      exit(2);
    }
  else if(pid>0)
    { /*padre*/
      wait(&stat);
      printf("ls concluso con esito %u\n",stat);
    }
  else /*figlio*/
    if(execlp("ls","-l",0)==-1)
      perror("main");
  
}
