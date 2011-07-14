#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
//#include"stdargs.h"

#define PERMS 0666
#define BUF 1024

main(int argc,char *argv[]){

  int fsource,fdest,control;
  char buff[BUF];
  
  if(argc!=3){
    puts("Error:numero argomenti.");
    return;
  }

  fsource=open(argv[1],O_RDONLY);

  if((fdest=open(argv[2],O_WRONLY))==-1)
    fdest=creat(argv[2],PERMS);

  while((control=read(fsource,buff,BUF))>0){
    if(write(fdest,buff,control)!=control){
      puts("Error:errore nella scrittura su file.");
      return;
    }
  }

}
