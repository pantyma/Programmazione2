#include<stdio.h>
#include<string.h>


#define MAXLINE 256

int countSubstr(char [],char []);

main(){

  char str[MAXLINE],substr[MAXLINE];
  int count=0;

  puts("Inserire una stringa.");
  fgets(str,MAXLINE,stdin);
  strtok(str,"\n");

  puts("Inserire la sottostringa che si vuole cercare.");
  fgets(substr,MAXLINE,stdin);
  strtok(substr,"\n");

  count=countSubstr(str,substr);

  if(count==-1)
    puts("Error:La sottostringa e` piu` lunga della stringa.");
  else
    printf("La sottostringa cercata e` presente %d volte nella stringa data.\n",count);
  
}

int countSubstr(char str[],char substr[]){

  int lensubstr,lenstr,i,cnt=0;

  lenstr=strlen(str);
  lensubstr=strlen(substr);

  if(lensubstr>lenstr)
    return -1;

  for( i=0 ; str[i]!='\0' ; i++){
    if(str[i]==substr[0] && !(strncmp(&str[i],substr,lensubstr))){
      cnt++;
      i+=(lensubstr-1);
    }
  }

  return cnt;
  
}
