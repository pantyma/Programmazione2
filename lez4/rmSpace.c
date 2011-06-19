#include<stdio.h>
#include<string.h>

#define MAXLINE 256

main(){
  char line[MAXLINE];
  int len=0;
  int rem=0;

  fgets(line,MAXLINE,stdin );
  strtok(line,"\n");

  len=strlen(line)-1;

  while((line[len]==' ') || (line[len]=='\t') || (line[len]=='\n')){
    line[len]='\0';
    len--;
    rem++;
  }

  printf("Sono stati rimossi %d spazi.\n",rem);
}
