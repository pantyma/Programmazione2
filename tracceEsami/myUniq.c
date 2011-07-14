/*
 * Traccia del 25 Febbraio 2011
 * Prencipe Mattia
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 1000

void usage();

main(int argc,char *argv[])
{
  int c,occor=1;
  FILE *fp;
  char line[MAXLINE];
  char precLine[MAXLINE]="";
  int cflag=0,dflag=0,uflag=0;
  
  if(argc==1)
    {
      while((fgets(line,MAXLINE,stdin))!=NULL)
	{
	  line[strlen(line)-1]='\0';
	  if(strcmp(line,precLine))
	    {
	      puts(line);
	      strcpy(precLine,line);
	    }
	}
    }
  else
    {
      while((c=getopt(argc,argv,":hcdu"))!=-1)
	switch(c)
	  {
	  case 'c':
	    cflag=1;
	    break;
	  case 'h':
	    usage();
	    exit(0);
	  case 'd':
	    dflag=1;
	    break;
	  case 'u':
	    uflag=1;
	    break;
	  case '?':
	    printf("L'opzione \"%c\" non e` riconosciuta.\n",optopt);
	    usage();
	    exit(1);
	  }
      if(argv[optind]==NULL)
	fp=stdin;
      else if((fp=fopen(argv[optind],"r"))==NULL)
	{
	  perror("Il file non puo` essere aperto in lettura o non esiste.");
	  exit(1);
	}
      
      if(fgets(precLine,MAXLINE,fp)!=NULL)
	{
	  precLine[strlen(precLine)-1]='\0';
	  while((fgets(line,MAXLINE,fp))!=NULL)
	    {
	      line[strlen(line)-1]='\0';
	      
	      if(strcmp(line,precLine)==0)
		{
		  occor++;
		  continue;
		  
		}
	      else
		{
		  if(cflag){
		    printf("%3d\t%30s\n",occor,precLine);
		    strcpy(precLine,line);
		    occor=1;
		    
		  }
		  else if(dflag){
		    if(occor>1){
		      printf("%s\n",precLine);
		      strcpy(precLine,line);
		      occor=1;
		    }
		    else
		      strcpy(precLine,line);
		  }
		  else if(uflag){
		    if(occor==1){
		      printf("%s\n",precLine);
		      strcpy(precLine,line);
		    }
		    else{
		      strcpy(precLine,line);
		      occor=1;
		    }
		  }
		  else
		    /* Ossia tutti i flag bassi. */
		    {
		      printf("%s\n",precLine);
		      strcpy(precLine,line);
		      occor=1;
		    }
		}
	    }
	}
      if(cflag){
	printf("%3d\t%30s\n",occor,precLine);
	exit(0);
      }
      if(dflag && occor>1){
	printf("%s\n",precLine);
	exit(0);
      }
      if(uflag && occor==1){
	printf("%s\n",precLine);
	exit(0);
      }
    }
 
}


void usage()
{
  printf("\nUSAGE MYUNIQ:\n\n");
  printf("./myUniq [opzioni] [file_name]\t Legge da file_name e in caso di piu` righe uguali consecutive ne stampa una sola.\n");
  printf("\t-c\t Fa precedere la riga dal numero di occorrenze di tale riga.\n");
  printf("\t-d\t Scarta le righe che non sono mai ripetute.\n");
  printf("\t-u\t Scarta completamente le righe ripetute.\n");
  printf("\t-h\t Visualizza l'usage di myUniq.\n");
  printf("In assenza di [file_name] la lettura avverra` dallo standard input.\n\n");
}
