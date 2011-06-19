#include<stdio.h>

main(){

  int c;
  int ch,word,space,line,initword;
  ch=word=space=line=initword=0;

  while((c=getchar())!=EOF){

    switch(c){
    case '\t':
      if(initword>0){
	ch++;
	word++;
	initword=0;
      }else{
	ch++;
      }
      break;
    case ' ':
      if(initword>0){
	ch++;
	space++;
	word++;
	initword=0;
      }else{
	ch++;
	space++;
      }
      break;
    case '\n':
      if(initword>0){
	ch++;
	word++;
	initword=0;
	line++;
      }else{
	ch++;
	line++;
      }
      break;
      default:	
	ch++;
	initword++;
	break;
    }
  }

    printf("Il testo contiene %d caratteri, %d parole, %d spazi vuoti, %d linee.\n",ch,word,space,line);
  }
