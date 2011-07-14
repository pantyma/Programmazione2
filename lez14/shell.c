#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "parse.h"

#define LINELENGTH 512
#define PROMPT ">"
#define PERMS 0666


main()
{

  int finish=0;
  char line[LINELENGTH];
  //char prompt[LINELENGTH];
  tcmdline cmd;

  //getcwd(prompt,LINELENGTH);
  //strcat(prompt,">");
  
  while(!finish)
    {
      //getcwd(prompt,LINELENGTH);
      printf("%s%s",get_current_dir_name(),PROMPT);
      fgets(line,LINELENGTH,stdin);
      line[strlen(line)-1]='\0';
      //puts(line);
      if(!strcmp(line,"exit")){
	printf("Bye bye.\n");
	finish=1;
      }
      else
	{
	  cmd=parseLine(line);
	  	  
	  if(cmd.command[0]!='\0')
	    {
	      char ** parms=(char **)malloc((cmd.numpar+1)*sizeof(char **));
	      int x=0;
	      
	      for(x=0;x<cmd.numpar;x++)
		parms[x]=cmd.param[x];
	      parms[cmd.numpar]=NULL;
	      //IMPLEMENTAZIONE DELLA SHELL
	      	     
	      pid_t pid=fork();

	      if(pid==-1)
		{
		  perror("Non posso eseguire il comando.\n");
		  exit(2);
		}
	      /* Processo figlio. */
	      
	      if(pid == 0)
		{
		 
		  /* Redirezione dell'input. */
		  if(cmd.inFile[0]!='\0')
		    {
		      int fd=open(cmd.inFile,O_RDONLY);
		      close(0);
		      dup(fd);
		      close(fd);
		    }
		  /* Redirezione dell'output. */
		  if(cmd.outFile[0]!='\0')
		    {
		      int fd=creat(cmd.outFile,PERMS);
		      close(1);
		      dup(fd);
		      close(fd);
		    }
		  /* Redirezione del file error. */
		  if(cmd.errFile[0]!='\0')
		    {
		      int fd=creat(cmd.errFile,PERMS);
		      close(2);
		      dup(fd);
		      close(fd);
		    }
		  
		  if(execvp(cmd.command,parms)==-1 && strcmp(cmd.command,"cd"))
		    printf("Non posso eseguire il comando %s\n",cmd.command);
		  exit(0);
		}
	      else
		{
		  /* Processo padre. */
		  int stat;
		  
		  /* Comando "cd" */
		  if(!strcmp(cmd.command,"cd") && cmd.numpar==2)
		    {
		      if(chdir(cmd.param[1])!=0)
			printf("%s : Directory non esistente.\n",cmd.param[1]);
		    }
		  
		  if(cmd.background)
		    printf("[1] %lu\n",pid);
		  else
		    wait(&stat);
		}

	      free(parms);
	    }
	  else
	    printf("Comando non valido.\n");
	}
    }
}
