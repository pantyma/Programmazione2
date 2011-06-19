#include<stdio.h>
#include<stdlib.h>

void usage();

main(int argc,char *argv[]){

  int c,ncampo,campo;
  char delim;

  delim=argv[1][0];
  ncampo=atoi(argv[2]);
  campo=ncampo;
  
  if(argc==3){
    while((c=getchar())!=EOF){
      if(c==delim)
	campo--;
      if(campo==1){
	while((c=getchar())!='\n')
	  putchar(c);
	campo=ncampo;
	printf("\n");
      }
    }

  }else{
    usage();
    return;
  }

}

void usage(){

  puts("MINICUT USAGE");
  puts("./minicut delim ncampo \t Stampa a video il campo numero ncampo contando i delimitatori delim.");
  
}
