#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include "parse.h"

#define LINELENGTH 512
#define PROMPT ">"
#define PERMS 0666
#define NUMCOMMANDS 10
#define COMMANDLENGTH 100


void exePipe(char *line);
void exeCmd(tcmdline cmd);
/* Prototipo dell'handler function. */
void sendInt();
void sendKill();

pid_t childPid;

main()
{

  int finish=0;
  char line[LINELENGTH];
  //char prompt[LINELENGTH];
  //tcmdline cmd;

  //getcwd(prompt,LINELENGTH);
  //strcat(prompt,">");
  
  while(!finish)
    {
      //getcwd(prompt,LINELENGTH);
      printf("tsh:%s%s",get_current_dir_name(),PROMPT);
      fgets(line,LINELENGTH,stdin);
      line[strlen(line)-1]='\0';
      if(!strcmp(line,"exit"))
	{
	  printf("Bye bye.\n");
	  finish=1;
	}
      else
	{
	  exePipe(line);
	}
    }
}


void sendKill()
{
  signal(SIGKILL,sendKill);
  kill(childPid,SIGKILL);
}

void sendInt()
{
  signal(SIGINT,sendInt);
  kill(childPid,SIGINT);  
}


void exePipe(char *line)
{
  tcmdline cmd[NUMCOMMANDS];
  int x,ncom=0;
  /* Per ogni NUMCOMMANDS abbiamo 2 fd per ridirezionare l'input e l'output dell'aventuale pipe. */
  int fd[NUMCOMMANDS][2];
  char *result=NULL;
  char strPiece[NUMCOMMANDS][COMMANDLENGTH];
  pid_t pid;

  /* Se riceve il segnale SIGINT ( ossia ctrl+C ) fa gestire il segnale dalla funzione sendInt. */
  signal(SIGINT,sendInt);
  signal(SIGKILL,sendKill);
  
  result=strtok(line,"|");
  while(result)
    {
      strcpy(strPiece[ncom++],result);
      result=strtok(NULL,"|");
    }

  for(x=0;x<ncom;x++)
    cmd[x]=parseLine(strPiece[x]);

  ncom--;
  for(x=ncom;x>=0;x--)
    {
      if(x!=ncom)
	pipe(fd[x]);
      
      pid=fork();
      if(pid==-1)
	{
	  perror("Non e` possibile eseguire il comando.\n");
	  exit(2);
	}
      /* Processo figlio. */
      if(pid==0)
	{
	  if(x<ncom)
	    {
	      close(1);
	      dup(fd[x][1]);
	      close(fd[x][0]);
	      close(fd[x][1]);
	    }
	  if(x==0)
	    exeCmd(cmd[x]);
	}
      else /* Processo padre. */
	{
	  /* Assegna alla variabile globale il pid dell'ultimo figlio, quello che esegue il primo comando. */
	  if(x==0)
	    childPid=pid;

	  if(x==ncom)
	    {
	      int stat;
	      if(cmd[ncom].background)
		printf("[1] %d\n",pid);
	      else
		wait(&stat);
	      break;
	    }
	  else
	    {
	      close(0);
	      dup(fd[x][0]);
	      close(fd[x][0]);
	      close(fd[x][1]);
	      exeCmd(cmd[x+1]);
	    }
	}
    }
}

void exeCmd(tcmdline cmd)
{
  if(cmd.command[0]!='\0')
    {
      char ** parms=(char **)malloc((cmd.numpar+1)*sizeof(char **));
      int x=0;
      
      for(x=0;x<cmd.numpar;x++)
	parms[x]=cmd.param[x];
      parms[cmd.numpar]=NULL;

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
      /* Comando "cd" */
      if(!strcmp(cmd.command,"cd"))
	{
	  if(chdir(cmd.param[1])!=0)
	    printf("%s : Directory non esistente.\n",cmd.param[1]);
	}
      if(execvp(cmd.command,parms)==-1 && strcmp(cmd.command,"cd"))
	printf("Non posso eseguire il comando %s\n",cmd.command);
      free(parms);
    }
  else
    {
      fprintf(stderr,"Comando non valido\n");
    }
}
