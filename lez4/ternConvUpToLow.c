#include<stdio.h>
#include<ctype.h>

int upToLow(int);

main(){

  int c,conv;

  while((c=getchar())!=EOF){
    conv=upToLow(c);
    printf("%c",conv);
  }
}

int upToLow(int c){

  return ( isupper(c) ? tolower(c) : toupper(c) );

}
