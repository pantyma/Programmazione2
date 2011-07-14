/*
 * Traccia del 28 Giugno 2011
 *
 * Prencipe Mattia
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAXLINE 512

void usage();
int execPipe(char *dirname);
int countLine(char *fileName);

main(int argc,char *argv[])
{
  int countline=0;
  
  if(argc==2)
    {
      //countline=countLine(argv[1]);
      countline=execPipe(argv[1]);
      if(countline!=-1)
      	printf("Sono state contate %d linee.\n",countline);
    }
  else
    {
      usage();
      return;
    }
    //execlp("find","find","-name","*.c",NULL);
}

int execPipe(char *dirname)
{
  int fd[2];
  int pid,stat;
  char line[MAXLINE];
  int totline=0;
  int cline=0;

  pipe(fd);
  pid=fork();

  if(pid==-1)
    {
      perror("Non e` possibile eseguire il comando.");
      exit(2);
    }
  if(pid==0)
    {
      close(1);
      dup(fd[1]);
      close(fd[0]);
      close(fd[1]);
      execlp("find","find",dirname,"-name","*.c",NULL);
    }
  else
    {
      close(0);
      dup(fd[0]);
      close(fd[0]);
      close(fd[1]);
      while(fgets(line,MAXLINE,stdin)!=NULL)
	{
	  line[strlen(line)-1]='\0';
	  if((cline=countLine(line))==-1)
	    return -1;
	  else
	    totline+=cline;
	}
      wait(&stat);
      return totline;
    }
}

int countLine(char *fileName)
{
  FILE *fp;
  char line[MAXLINE];
  int cline=0;

  if((fp=fopen(fileName,"r"))!=NULL)
    {
      while(fgets(line,MAXLINE,fp)!=NULL)
	cline++;
      //printf("Il file %s contiene %d linee.\n",fileName,cline);
      fflush(stdout);
      fclose(fp);
      return cline;
    }
  else
    {
      printf("Il file %s non puo` essere aperto.\n",fileName);
      //perror("Il file non puo` essere aperto.");
      return -1;
    }
  
}
void usage()
{
  printf("USAGE \"countLine\" :\n\n");
  printf("./countLine [dirname]\t A partire dalla directory \"dirname\" apre tutti file .c ne conta il numero di linee\n\t e stampa il totale delle linee di tutti i file trovati.\n\n");

}
