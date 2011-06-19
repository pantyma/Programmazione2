#include<stdio.h>
#include<string.h>

#define MAXLINE 256

int strIndex(char [],char []);

main(){

  char stringa[MAXLINE];
  char substr[MAXLINE];
  int index=0;

  puts("Inserire la stringa nella quale cercare.");
  fgets(stringa,MAXLINE,stdin);
  strtok(stringa,"\n");

  puts("Inserire la sottostringa da cercare.");
  fgets(substr,MAXLINE,stdin);
  strtok(substr,"\n");

  index=strIndex(stringa,substr);

  if(index==-1)
    puts("La sottostringa potrebbe essere piu` lunga della stringa oppure non essere presente nella stringa data.");
  else
    printf("La sottostringa e` presente nella stringa all'indice %d.\n",index);

}

//Cerca l'indice della sottostringa in una stringa data.
//Usa il continue

/* int strIndex(char stringa[],char substr[]){ */

/*   int lenstr,lensubstr,index=-1; */
/*   int i=0,j=0; */

/*   lenstr=strlen(stringa); */
/*   lensubstr=strlen(substr); */

/*   //Se la sottostringa e` piu` lunga della stringa ritorna -1 che indica un'anomalia */
/*   if(lenstr<lensubstr) */
/*     return -1; */

/*   while(i<(lenstr-lensubstr+1)){ */
/*     if(stringa[i]!=substr[j]){ */
/*       i++; */
/*       continue; */
/*     }else{ */
/*       j++; */
/*       while(stringa[i+j]==substr[j] && j<lensubstr) */
/* 	j++; */
/*       if(j==lensubstr) */
/* 	return i; */
/*       else{ */
/* 	j=0; */
/* 	i++; */
/*       } */
/*     } */
/*   } */
  
/*   return -1; */
  
/* } */

//Non usa il continue ed e` piu` compatto

int strIndex(char s1[],char s2[]){

  int len1=0,len2=0,i;

  len1=strlen(s1);
  len2=strlen(s2);

  if(len2>len1)
    return -1;

  for(i=0;i<len1;i++){
    if(s1[i]==s2[0])
      if(strncmp(&s1[i],s2,len2)==0)
	return (i+1);
  }

  return -1;
}
