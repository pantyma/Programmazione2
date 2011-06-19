#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXLINE 256

int searchReplace(char *,char *,char *);

main(){

  char str[MAXLINE],substr[MAXLINE],rpl[MAXLINE];
  int position=0;

  puts("Inserire una stringa.");
  fgets(str,MAXLINE,stdin);
  strtok(str,"\n");

  puts("Inserire la sottostringa che si vuole rimpiazzare.");
  fgets(substr,MAXLINE,stdin);
  strtok(substr,"\n");

  puts("Inserire il testo da sostituire al precedente.");
  fgets(rpl,MAXLINE,stdin);
  strtok(rpl,"\n");

  if( (strlen(str)-strlen(substr)+strlen(rpl)) > MAXLINE) {
    puts("Error:la sostituzione non puo` avvenire per mancanza di spazio.");
    return;
  }

  position=searchReplace(str,substr,rpl);
  
  if(position==-1)
    puts("Error:La sostituzione non e` andata a buon fine.");
  else
    printf("La stringa risultante e` \"%s\" e la sostituzione e` avvenuta nella posizione %d\n",str,position);

}

int searchReplace(char str[], char substr[], char rpl[]) {

  //Con pos (posizione della sottostringa) uguale a -1 si indica un anomalia generica.
  
  int lensubstr=strlen(substr);
  int i,pos=-1;
  char temp[MAXLINE];

  for( i=0 ; str[i]!='\0' ; i++){
    if(str[i]==substr[0] && !(strncmp(&str[i],substr,lensubstr))){
      pos=i;
      str[i]='\0';
      break;
    }
  }
  
  strcpy(temp,&str[pos+lensubstr]);
  strcat(str,rpl);
  strcat(str,temp);
  
  return pos;
}
