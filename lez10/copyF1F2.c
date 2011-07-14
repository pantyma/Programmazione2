#include<stdio.h>


main(int argc,char *argv[]){

  FILE *fp1,*fp2;
  int c;
  
  if(argc!=3){

    puts("Error: numero parametri non corretto.");
    return;

  }
  
  fp1=fopen(argv[1],"r");
  fp2=fopen(argv[2],"w");

  if( (fp1==NULL) || (fp2==NULL)){
    puts("Error: problemi nell'apertura di uno dei due file.");
    return ;
  }
  
  while((c=getc(fp1))!=EOF)
    putc(c,fp2);

  fclose(fp1);
  fclose(fp2);
  
}
