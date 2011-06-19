#include<stdio.h>

int maxTern(int,int);

main(){

  int x,y,max=0;

  printf("Inserire due numeri.\n");
  scanf("%d %d",&x,&y);

  max=maxTern(x,y);
  printf("Il massimo tra i due numeri e` %d\n",max);
}

int maxTern(int x,int y){

  return ((x>y) ? x : y);

}
