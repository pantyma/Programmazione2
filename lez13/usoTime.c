#include <sys/types.h>
#include <sys/times.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

main()
{
  int stat;
  struct tms buftimes;
  int pid=fork();
  
  if(pid<0)
    {
      perror("main");
      exit(2);
    }
  else if(pid>0)
    {
      /*padre*/
      wait(&stat);
      printf("ls concluso con esito %u\n",stat);
      clock_t t=times(&buftimes);
      printf("System time: %u\n",buftimes.tms_cstime);
      printf("User time: %u\n",buftimes.tms_cutime);
      printf("Wall clock: %u\n",t);
    }
  else
    /*figlio*/
    if(execlp("ls","-l",0)==-1)
      perror("main");
  
}
