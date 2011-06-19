#include<stdio.h>
#include<ctype.h>

int strToNum(char *);

main(){

  int i,c,result=0;
  char line[100];
  
  for(i=0;i<100;i++)
    line[i]='\0';

  for(i=0;(c=getchar())!='\n';i++)
    line[i]=c;
  
  if(!isdigit(line[0])){
    printf("Error:il primo carattere non e` un numero.\n");
    return;
  }
  
  result = strToNum(line);
  printf("Il numero e` %d.\n",result);
  
}

int strToNum(char *line){

  int n=0;
  
  while((*line != '\0') && (*line >= '0' && *line <= '9')){
    n = 10 * n + (*line-'0');
    line++;
  }
  
  return n;
}
