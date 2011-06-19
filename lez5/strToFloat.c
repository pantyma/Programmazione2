#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXLINE 256


float aTof(char str[]);

main(){

  char line[MAXLINE];
  float number;

  puts("Inserire la stringa del numero float.");
  fgets(line,MAXLINE,stdin);
  strtok(line,"\n");
  
  if(isdigit(line[0])||(line[0]=='.'))
    number=aTof(line);
  else{
    puts("La stringa inserita non e` convertibile in float.");
    return;
  }

  printf("Il numero float e` %.3f\n",number);

}

float aTof(char str[]){

  float n=0.0,dec=10.0;
  int i=0;
  
  while(isdigit(str[i])){
    n=(n*10)+(str[i++]-'0');
  }

  if(str[i]=='.')
    i++;

  while(isdigit(str[i])){
    n=n+((str[i++]-'0')/dec);
    dec*=10.0;
  }

  return n;

}
