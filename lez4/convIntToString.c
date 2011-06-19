#include<stdio.h>
#include<string.h>

#define MAXLINE 256

void intToString(int,char []);
void reverse(char []);

main(){

  int numb,i=0;
  char line[MAXLINE];
  while(i<MAXLINE)
    line[i++]='\0';

  puts("Inserire un numero intero.");
  scanf("%d",&numb);

  intToString(numb,line);
  
  reverse(line);

  printf("Il numero in formato stringa e` %s\n",line);
}

void intToString(int n,char line[]){

  int i=0;
  char segno;
  
  if(n<0){
    segno='-';
    n*=-1;
  }

  while((n/10)>0){
    line[i]=(n%10)+'0';
    i++;
    n/=10;
  }
  line[i]=(n%10)+'0';
  if(segno=='-')
    line[++i]=segno;

}

void reverse(char line[]){
  
  int len=0,i;
  char c;

  len=strlen(line)-1;

  for(i=0,len;i<len;i++,len--){
    c=line[i];
    line[i]=line[len];
    line[len]=c;
  }

}
