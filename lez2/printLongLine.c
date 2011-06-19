#include<stdio.h>

void mycopy(char *,char *);

main(){

  int c, len, maxlen=0;
  char line[100];
  char maxline[100];

  while((c=getchar())!=EOF){
    for(len=0; c!='\n'; len++){
      line[len]=c;
      c=getchar();
    }

    if(++len>maxlen){
      mycopy(line,maxline);
      maxlen=len;
    }
  }

  printf("La stringa piu` lunga e` \"%s\" di lunghezza %d.\n",maxline,maxlen);
}

void mycopy(char *line,char *maxline){

  while(*line!='\0'){
    *maxline=*line;
    maxline++;
    line++;
  }
  
}
