#include<stdio.h>

#define MAXLINE 1000

unsigned int setBits(unsigned int, int, int, unsigned int);
void printBinary(unsigned int numb);

main(){
  
  unsigned int x;
  unsigned int y;
  int p;
  int n;

  puts("Scrivere due interi senza segno.");
  scanf("%u %u",&x,&y);
  puts("Scrivere il punto di partenza per modificare x e il numero di bit meno significativi di y da sostituire.");
  scanf("%d %d",&p,&n);

  printf("In binario X vale ");
  printBinary(x);
  printf(" Y vale ");
  printBinary(y);
  puts("");
    
  x=setBits(x,p,n,y);
  
  printf("X modificata in binario vale ");
  printBinary(x);
  puts("");

}

void printBinary(unsigned int numb){

  int bin[64],i=0;

  while((numb/2)!=0){
    bin[i++]=numb%2;
    numb/=2;
  }
  bin[i]=numb;
  
  while(i>=0)
    printf("%d",bin[i--]);

}

unsigned int setBits(unsigned int x, int p, int n, unsigned int y){

  unsigned int mask;

  mask=(~(~0 << n)) << (p-n);

  return (unsigned int)((x & (~mask)) | ((y<<(p-n)) & mask));


}
