#include<stdio.h>
#include<string.h>

#define MAXLINE 256

int strIndexc(char [],char);

main(){

  char stringa[MAXLINE];
  char t;
  int index=0;
  
  puts("Inserire la stringa nella quale cercare.");
  fgets(stringa,MAXLINE,stdin);
  strtok(stringa,"\n");
  puts("Inserire il carattere da cercare.");
  t=getchar();

  index=strIndexc(stringa,t);

  if(index==-1)
    puts("Il carattere non e` stato trovato.");
  else
    printf("Il carattere e` presente in posizione %d\n",index);

}

int strIndexc(char str[],char t){

  int i=0;
  
  while(str[i]!='\0'){

    if(str[i]==t)
      return i;
    else
      i++;
  }

  return -1;
  
}
