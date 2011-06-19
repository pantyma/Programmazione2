//Non funzionante

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXLINE 1000

//Da controllare : errore di segmentazione.

void usage();
void printReverce(char line[],int len);

main(int argc,char *argv[]){

  int nline,ch,i;
  char buffer[MAXLINE];
  char c='0'+argc;

  switch (c) {
  case '1':
    nline=10;
    break;
  case '2':
    if((argv[1][0]=='-') && (isdigit(argv[1][1])))
      nline=atoi(argv[1])*(-1);
    else{
      puts("Error: parametro non valido.\n");
      usage();
    }
    break;
  case '3':
    if(!strcmp(argv[1],"-n") && (isdigit(argv[2]))){
      if((nline=atoi(argv[2]))<0)
	nline*=-1;
    }else{
      puts("Error: parametro non valido.\n");
      usage();
    }
    break;
  default :
    usage();
    break;
  }

  fseek(stdin,0,SEEK_END);
  while(nline > 0){
    for(i=0;(ch=getchar())!= '\n';i++)
      buffer[i]=ch;
    buffer[i]='\0';
    printReverce(buffer,i);
    nline--;
  }

}

void printReverce(char line[],int len){

  while(--len>=0)
    putchar(line[len]);
  
  putchar('\n');
  
}

void usage(){

  puts(" Tail usage:");
  puts("\t./tail < file \t Stampa su stdout le ultime 10 linee di file.");
  puts("\t./tail -n num < file \t Stampa su stdout le ultime num linee di file.");
  puts("\t./tail -num < file \t Stampa su stdout le ultime num linee di file.");

}
