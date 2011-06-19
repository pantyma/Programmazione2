//Da controllare e completare

#include<stdio.h>
#include <string.h>

#define MAXLINES 5000

//Prototipi delle funzioni

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);
int partition(char *v[], int left, int right);
void cleanup(char *lineptr[], int nlines);
int profgetline(char *s,int maxlen);

main(){
  
  char *lineptr[MAXLINES];
  int nlines;

  if((nlines = readlines(lineptr, MAXLINES)) >= 0){

    qsort(lineptr, 0, nlines-1);
    writelines(lineptr, nlines);
    cleanup(lineptr, nlines);
    return 0;
    
  }else{
    
    printf("error: input too big to sort\n");
    return 1;

  }
  
}


int readlines(char *lineptr[], int maxlines){

  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;

  while(profgetline(line,MAXLEN)!=EOF)

    if(nlines >= maxlines ||(p=(char*)malloc(strlen(line)*sizeof(char)))==NULL)
      return -1;

    else {
      strcpy(p, line);
      lineptr[nlines++] = p;
    }

  return nlines;
}

int profgetline(char *s,int maxlen){

  char c;
  int i=0;
  
  for(i=0;i<maxlen &&(c=*s++=getchar())!=EOF &&	c!='\n';i++);
  
  *(s-1)='\0';

  if(c==EOF)
    return 0;
  else
    return i;
  
}

void qsort(char *v[], int left, int right){
  
  int i,x;

  if(left<right){
    
      i=partition(v, left, right);
      qsort(v,left,i-1);
      qsort(v,i+1,right);
      
  }
  
}

//Versione semplificata di qsort

/* void qsort(char *v[], int left, int right){ */
  
/*   int i, last; */

/*   /\* fa nulla se l’array contiene *\/ */
/*   /\* meno di due elementi *\/ */
  
/*   if (left >= right)  */
/*     return; */
  
/*   /\* sposta il pivot*\/ */
/*   /\* in prima pos. *\/ */
  
/*   swap(v, left, (left + right)/2); */
/*   last = left; */
    
/*   for (i = left+1; i <= right; i++) */
/*     if (strcmp(v[i], v[left]) < 0) */
/*       swap(v, ++last, i); */

/*   /\* rimette a posto il pivot *\/ */
  
/*   swap(v, left, last); */
 
/*   qsort(v, left, last-1); */
/*   qsort(v, last+1, right); */
  
/* } */


int partition(char *v[], int left, int right){
  
  int i=left;
  int j=right;
  char x[MAXLEN];
  
  strcpy(x,v[left]);
  while(i<j){
    
      while(strcmp(v[j],x)>0)
	j--;
      
      if(i<j){
	swap(v,i++,j);
	while(strcmp(v[i],x)<0)
	  i++;
	if(i<j)
	  swap(v,i,j--);
      }
    }
  
  return i;
  
}


void writelines(char *lineptr[], int nlines){
  
  int i;
  
  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
  
}

void cleanup(char *lineptr[], int nlines){
  
  int i;
  
  for (i = 0; i < nlines; i++)
    free(lineptr[i]);
  
}
