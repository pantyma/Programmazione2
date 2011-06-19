#include<stdio.h>

//Commento di prova per testare il programma

main(){

  int c,c2;
  /*

    Provo anche il commento
    su piu` linee.

  */
  while((c=getchar())!=EOF){
    if(c=='/'){
      c=getchar();
      switch (c) {
      case '/':
	  while((c=getchar())!='\n');
	  break;
      
      case '*':
	  c2=getchar();
	  while(((c=c2)!='*') && ((c2=getchar())!='/'));
	  break;
    
      default:
	  putchar(c);
	  break;
      }

    }else{

      putchar(c);

    }
    
  }

}
