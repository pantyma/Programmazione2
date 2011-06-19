#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct nodeWord{
  char word[100];
  struct nodeWord *left;
  struct nodeWord *right;
};



void usage();
void clean(char *);
struct nodeWord *addword(struct nodeWord *albero,char parola[]);
void treeprint(struct nodeWord *p);
void searcWord(struct nodeWord *p,char *parola);



main(int argc,char *argv[]){

  FILE *fp1;
  FILE *fp2;
  int c,i;
  char word[100];
  struct nodeWord *albero = NULL;
  
  if(argc!=3){
    puts("Error: chiamata non corretta.");
    usage();
    return (1);
  }

  clean(argv[1]);
  clean(argv[2]);
  fp1=fopen("lessPunctF1","r");

  while((c=fgetc(fp1))!=EOF){
    word[0]='\0';
    for(i=0;(c!=' ')&&(c!='\n');i++){
      word[i]=(char)c;
      word[i+1]='\0';
      c=fgetc(fp1);
    }
    if(word[0]!='\0')
      albero=addword(albero,word);
  }

  fp2=fopen("lessPunctF2","r");
  puts("Parole comuni tra i file passati.");
  
  while((c=fgetc(fp2))!=EOF){
    word[0]='\0';
    for(i=0;(c!=' ')&&(c!='\n');i++){
      word[i]=(char)c;
      word[i+1]='\0';
      c=fgetc(fp2);
    }
    if(word[0]!='\0')
      searcWord(albero,word);
  }

  //treeprint(albero);

}

/* Controllo se la parola passata e` presente nel primo file.Se si la stampo. */

void searcWord(struct nodeWord *p,char *parola){

  int result;
  
  if(p!=NULL){
    result=strcmp(parola,(p->word));
    if(result==0)
      printf("%s\n",parola);
    if(result>0)
      searcWord(p->right,parola);
    if(result<0)
      searcWord(p->left,parola);
  }

}

/* Aggiunge una parola all'albero. */

struct nodeWord *addword(struct nodeWord *albero,char parola[100]){

  int controllo;
  
  if(albero==NULL){
    albero= (struct nodeWord *)malloc(sizeof(struct nodeWord));
    strcpy(albero->word,parola);
    albero->left=NULL;
    albero->right=NULL;
  }else{
    controllo=strcmp(parola,(albero->word));
    if(controllo==0)
      return albero;
    else if(controllo<0)
      albero->left=addword((albero->left),parola);
    else if(controllo>0)
      albero->right=addword((albero->right),parola);
  }
  return albero;

}

/* Stampa l'abero */

void treeprint(struct nodeWord *p){

  if( p != NULL){
    treeprint(p->left);
    printf("%s\t",p->word);
    treeprint(p->right);
  }
  
}

/* Pulisce il file dai segni di punteggiatura. */

void clean(char *nfile){

  char line[100]="cat ";
  static char *i="1";
  
  strcat(line,nfile);
  strcat(line," | tr '[:punct:]' ' ' | tr '\n' ' ' > lessPunctF");
  strcat(line,i);
  system(line);
  i="2";

}

void usage(){

  puts("searchCommonWords usage.");
  puts("./usage file1 file2 \t stampa una lista di parole comuni tra file1 e file2.");

}

