#include<stdio.h>

main(){

  char str[]="Stringa di prova.";
  int i,length=0;

  for(i=0;str[i]!='\0';i++)
    length++;

  printf("La stringa e` lunga %d.\n",length);
}
