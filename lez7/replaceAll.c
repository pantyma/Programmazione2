#include<stdio.h>
#include<string.h>

#define MAXLINE 256

void replaceStr(char [] , int , char []);

main(){

  char str[MAXLINE],substr[MAXLINE],rpl[MAXLINE];
  int i,lensubstr;

  puts("Inserire una stringa.");
  fgets(str,MAXLINE,stdin);
  strtok(str,"\n");

  puts("Inserire la sottostringa che si vuole rimpiazzare.");
  fgets(substr,MAXLINE,stdin);
  strtok(substr,"\n");

  puts("Inserire il testo da sostituire al precedente.");
  fgets(rpl,MAXLINE,stdin);
  strtok(rpl,"\n");

  lensubstr=strlen(substr);
  
  for( i=0 ; str[i]!='\0' ; i++){
    if(str[i]==substr[0] && !(strncmp(&str[i],substr,lensubstr))){
      replaceStr(&str[i],lensubstr,rpl);
    }
  }

  printf("La stringa modificata e` \"%s\"\n",str);
}

void replaceStr(char stringa[],int lensubstr,char replace[]){
  
  char temp[MAXLINE];
  
  strcpy(temp,&stringa[lensubstr]);
  stringa[0]='\0';
  strcat(stringa,replace);
  strcat(stringa,temp);

}
