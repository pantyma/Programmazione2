#include<stdio.h>
#include<unistd.h>

void usage();

main(int argc,char *argv[]){

  int c;
  int car;
  int nline=0,nchar=0,nword=0;

  while((car=getchar())!=EOF){
      nchar++;
      if(car=='\n')
  	nline++;
      if(car==' ')
  	nword++;
  }

  if(argc>1){

    while((c=getopt(argc,argv,"lcw")) != -1)

      switch (c){
	
      case 'l':
	printf("Nel file sono presenti %d linee.\n",nline);
	break;
	
      case 'c':
	printf("Nel file sono presenti %d caratteri.\n",nchar);
	break;
	
      case 'w':
	printf("Nel file sono presenti %d parole.\n",nword);
	break;
	
      case '?':
	puts("Error: parametro non riconosciuto.\n");
	usage();
	break;
      }
    
  }else{

    printf("Nel file sono presenti %d linee.\n",nline);
    printf("Nel file sono presenti %d caratteri.\n",nchar);
    printf("Nel file sono presenti %d parole.\n",nword);

  }

}

void usage(){

  puts("WC USAGE");
  puts("\t ./wc < file \t Stampa per default il numero di linee,caratteri e parole di file.");
  puts("\t ./wc -l < file \t Stampa il numero di linee di file.");
  puts("\t ./wc -c < file \t Stampa il numero di caratteri di file.");
  puts("\t ./wc -w < file \t Stampa il numero di parole di file.");

}
