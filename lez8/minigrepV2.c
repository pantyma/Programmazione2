#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<unistd.h>

#define MAXLINE 1000

void printpar(char *str, char c, char n, char v);
void usage();

static int caSens=1;

//getopt restituisce ':' se non c'e` l'argomento previsto da quella opzione.
//restituisce '?' se l'opzione non e` riconosciuta.
//optarg contiene il puntatore alla stringa argomento dell'opzione.

main(int argc,char *argv[]){

  int i;
  char c,n,v;
  c=n=v=' ';

  opterr=0;
  
  while((i=getopt(argc,argv,":c:n:v:i"))!=-1){
    switch (i){
    case 'i':
      caSens=0;
      break;
    case 'c':
      c='c';
      break;
    case 'n':
      n='n';
      break;
    case 'v':
      v='v';
      break;
    case ':':
      puts("Error:Le opzioni -c -n -v richiedono un argomento.");
      usage();
      return;
      break;
    case '?':
      printf("Error:L'opzione %c non e` riconosciuta.\n",optopt);
      usage();
      return;
      break;
    }
  }

  printpar(argv[2],c,n,v);

}

void printpar(char *stringa, char c, char n, char v){

  char line[MAXLINE];
  char *templine;
  int controll,number,countMatch=0;

  if(caSens==1){
    for(number=1; fgets(line,MAXLINE,stdin) != NULL; number++){
      templine=strstr(line,stringa);
      if((templine == NULL) && (v=='v'))
	printf("%s",line);
      if((templine != NULL) && (n=='n'))
	printf("%d. %s",number,line);
      if((templine != NULL) && (c=='c'))
	countMatch++;
    }
  }else{
    for(number=1;fgets(line,MAXLINE,stdin) != NULL; number++){
      controll=strcasestr(line,stringa);
      if((controll == 0) && (v=='v'))
   	printf("%s",line);
      if((controll != 0) && (n=='n'))
   	printf("%d. %s",number,line);
      if((controll != 0) && (c=='c'))
   	countMatch++;
    }
   }
  
  if(c=='c')
    printf("Sono stati contati %d match con la stringa data.\n",countMatch);
  
}

void usage(){

  puts("MINIGREP USAGE:");
  puts("\t -i < file \t\t non richiede un argomento e rende la ricerca case-insensitive.");
  puts("\t -c stringa < file \t richiede un argomento e stampa il numero di match con stringa incontrati nel file.");
  puts("\t -n stringa < file \t richiede un argomento e stampa le righe di file che contengono stringa.");
  puts("\t -v stringa < file \t richiede un argomento e stampa le righe di file che non contengono stringa.");

}
