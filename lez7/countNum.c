#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXLINE 256

main(){

  char line[MAXLINE];
  int i,numbers=0;
  
  fgets(line,MAXLINE,stdin);
  strtok(line,"\n");

  for(i=0;line[i]!='\0';i++){
    if(isdigit(line[i]))
      numbers++;
  }

  printf("Nella stringa ci sono %d caratteri numerici.\n",numbers);

}
