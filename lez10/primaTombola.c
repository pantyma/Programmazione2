#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define frand() ((double)rand()/(RAND_MAX+1.0)*90)

main(){

  int estratti[90];
  int tombola[90];
  int number,i,count=0;

  for(i=0;i<90;i++)
    estratti[i]=0;
  
  srand((unsigned int)time(NULL));

  for(i=0;i<90;){
    number=(frand()+1);
    if(estratti[number]!=1)
      tombola[i++]=number;
  }

  for(i=0;i<90;i++){
    if(count==10){
      printf("\n");
      count=0;
    }
    printf("%3d  ",tombola[i]);
    count++;
  }
  printf("\n");
}
