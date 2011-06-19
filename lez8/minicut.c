#include<stdio.h>
#include<unistd.h>

void usage();

main(int argc,char *argv[]){

  int c,nc,campo;
  char delim;

  while((c=getopt(argc,argv,":d:f:"))!=-1){

    switch (c){
      case 'd':
	delim=optarg[0];
	break;
      case 'f':
	nc=atoi(optarg);
	campo=nc;
	break;
      case ':':
	printf("L'opzione %c richiede un argomento.\n",optopt);
	usage();
	return;
	break;
      case'?':
	printf("L'opzione %c non e` riconosciuta.\n",optopt);
	usage();
	return;
	break;
      }
  }
  while((c=getchar())!=EOF){
    if(c==delim)
      campo--;
    if(campo==1){
      while((c=getchar())!='\n')
	putchar(c);
      printf("\n");
      campo=nc;
    }
  }
    
  
}

void usage(){
  
  puts("MINICUT USAGE");
  puts("./minicut -d delim -f numcampo \t Stampa a video il campo numero numcampo considerando come delimitatore delim.");

}
