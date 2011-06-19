#include<stdio.h>

//Riconosce e classifica il carattere digitato usando degli if innestati.


main(){

  int c;

  printf("Inserire un carattere.\n");
  c=getchar();

  if(c <= '0' || c >= '9')
    
    if(c <= 'a' || c >= 'z')
      
      if(c <= 'A' || c>= 'Z')

	if(c!='(' && c!=')' && c!='[' && c!=']' && c!='{' && c!='}')

	  if(c!='.' && c!=',' && c!='?' && c!='!' && c!=';' && c!=':')

	    if(c!='+' && c!='-' && c!='*' && c!='/' && c!='%' && c!='=')

	      printf("E` un simbolo.\n");
	    else
	      printf("E` un operatore aritmetico.\n");
	  else
	    printf("E` un segno di punteggiatura.\n");
	else
	  printf("E` una parentesi.\n");
      else
	printf("E` un carattere maiuscolo.\n");
    else
      printf("E` un carattere minuscolo.\n");
  else
    printf("E` una cifra.\n");
}
