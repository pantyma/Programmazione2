#include<stdio.h>

main(){

  int c,count=0;

  while((c=getchar())!=EOF)
    count++;

  printf("Sono stati contati %d caratteri.\n",count);
}

