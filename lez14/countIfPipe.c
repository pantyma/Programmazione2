#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define LLENGTH 256

main(int argc, char **argv)
{
  int fd[2];
  int stat;
  unsigned int numif=0;
  char line[LLENGTH];

  if(argc==2) // produttore
    {
      pipe(fd);
      if(fork()==0)
	{
	  /* Processo figlio: cattura le linee del file argv[1] contenenti la parola "if" e le butta nella pipe. */
	  close(1);
	  dup(fd[1]);
	  close(fd[0]);
	  close(fd[1]);
	  execlp("grep","grep","if",argv[1],NULL);
	}
      else
	{
	  /*
	   * Processo padre: legge dalla pipe le singole linee e incrementa il contatore degli "if".Quando il processo
	   * figlio termina, stampa il numero di "if" trovati.
	   */  
	  close(0);
	  dup(fd[0]);
	  close(fd[0]);
	  close(fd[1]);
	  while(fgets(line,LLENGTH,stdin))
	    numif++;
	  wait(&stat);
	  printf("Il file contiene %u if\n",numif);
	}
    }
}
