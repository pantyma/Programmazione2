#include<stdio.h>
#include<string.h>
#define MAXLINE 100

void upToLowStr(char str[MAXLINE]);

main(){

  int c,i;
  char str[MAXLINE];
  for(i=0;i<MAXLINE;i++)
    str[i]='\0';

  while(fgets(str,MAXLINE,stdin)!=NULL){
    strtok(str,"\n");
    upToLowStr(str);
    puts(str);
  }

}

void upToLowStr(char line[]){

  int i,c;
  for(i=0;line[i]!='\0';i++){
    if(line[i]>='A' && line[i]<='Z')
      line[i]+=('a'-'A');
  }
}
