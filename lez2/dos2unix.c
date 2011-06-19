#include<stdio.h>

main(){

  int c;

  while((c=getchar())!=EOF){
    if(c!='\r')
      printf("%c",c);
  }
  
}
