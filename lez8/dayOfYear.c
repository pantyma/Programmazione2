#include<stdio.h>

static char daytab[2][13] = {
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);

main(){

  int gg,mm,aa,bis;
  int dofy=0;
  
  puts("Inserire giorno/mese/anno in formato numerico.");
  scanf("%d/%d/%d",&gg,&mm,&aa);

  bis = (aa%4 == 0) && (aa%100 !=0) || (aa%400 == 0);

  if((mm>0 && mm<13) && (gg>0 && gg<=daytab[bis][mm])){
    dofy=day_of_year(aa,mm,gg);
    printf("Il totale giorni e`: %d\n",dofy);
  }else
    puts("Error: la data inserita non e` corretta.");
  
}

int day_of_year(int year, int month, int day){
  
  int i, leap;
  
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  
  for (i = 1; i < month; i++)
    day += daytab[leap][i];
  
  return day;
}

