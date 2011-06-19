#include<stdio.h>

#define SWAP(x,y,t)   t temp;\
                      temp=x;\
		      x=y;\
		      y=temp;

main(){

  int x=10,y=14;

  printf("Prima della macro x vale %d e y vale %d\n",x,y);

  SWAP(x,y,int);

  printf("Dopo la macro x vale %d e y vale %d\n",x,y);
}
