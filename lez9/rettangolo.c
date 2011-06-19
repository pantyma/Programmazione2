#include<stdio.h>

struct Point{
  int x;
  int y;
};

struct Rect{
  struct Point pa;
  struct Point pb;
};

int areaRettangolo(struct Rect r){

  int base=0,altezza=0;

  base = ((r.pb).x)-((r.pa).x);
  altezza = ((r.pb).y)-((r.pa).y);

  return (base*altezza);
}


main(){

  int area=0,base=0,altezza=0;
  
  struct Point p1,p2;
  
  struct Rect rettangolo;

  puts("Creazione rettangolo.");
  puts("Inserire le coordinate del primo punto in basso a sinistra.");
  scanf("%d %d",&(p1.x),&(p1.y));
  puts("Inserire le coordinate del secondo punto in alto a destra.");
  scanf("%d %d",&(p2.x),&(p2.y));

  rettangolo.pa=p1;
  
  rettangolo.pb=p2;
  
  area=areaRettangolo(rettangolo);
  
  printf("Il rettangolo creato ha coordinate p1(%d,%d) e p2(%d,%d).\n",p1.x,p1.y,p2.x,p2.y);
  printf("L'area calcolata e` %d\n",area);

}


