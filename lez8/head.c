#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAXLINE 1000

void usage();

main(int argc,char *argv[]){

  char c,line[MAXLINE];
  int nl;

  c='0'+argc;

  switch(c){
  case '1':
    nl=10;
    break;
  case '2':
    if((argv[1][0]=='-') && (isdigit(argv[1][1])!=0)){
      nl=atoi(argv[1])*(-1);
    }else{
      puts("Error: parametro non valido.");
      usage();
      return ;
    }
    break;
  case '3':
    if((strcmp(argv[1],"-n")==0) && (isdigit(*argv[2])))
	nl=atoi(argv[2]);
    else{
      puts("Error: parametro non valido.");
      usage();
      return ;
    }
    break;
  default :
    usage();
    return;
    break;
  }
  
    while(nl>0){
      fgets(line,MAXLINE,stdin);
      strtok(line,"\n");
      printf("%s\n",line);
      nl--;
    }
}

void usage(){

  puts(" Head usage:");
  puts("\t./head < file \t Stampa su stdout le prime 10 linee di file.");
  puts("\t./head -n num < file \t Stampa su stdout le prime num linee di file.");
  puts("\t./head -num < file \t Stampa su stdout le prime num linee di file.");

}
