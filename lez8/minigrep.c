//Da controllare

#include<stdio.h>
#include <string.h>

#define MAXLINE 1000

void printpar(char *,char);

main(int argc, char *argv[]){
  
  char line[MAXLINE];
  int found = 0;
  
  if (argc == 2){
    while (fgets(line, MAXLINE, stdin) != NULL)
      if (strstr(line, argv[1]) != NULL) {
	printf("%s", line);
	found++;
      }
  }else{
    if(argc == 3){
      if(argv[1][0] == '-'){
	switch (argv[1][1]){
	case 'v':
	  printpar(argv[2],argv[1][1]);
	  break;
        case 'n':
	  printpar(argv[2],argv[1][1]);
	  break;
	}
      }else{
	puts("Error:parametro invalido.");
	return;
      }
    }else{
      puts("Error:non sono previsti meno di un argomento o piu` di due parametri.");
      return;
    }
  }
  
  
  return found;
}

void printpar(char *str, char c){

  char line[MAXLINE];
  int number;

  if(c=='v'){
    while(fgets(line,MAXLINE,stdin) != NULL)
      if(strstr(line,str) == NULL)
	printf("%s",line);
  }
  if(c=='n'){
    for(number=1; fgets(line,MAXLINE,stdin) != NULL; number++)
      if(strstr(line,str) != NULL)
	printf("%d. %s",number,line);
  }

}
