#include<stdio.h>
#include<stdlib.h>

void readMatrix(int ***matrix,int *rig,int *col);
void printMatrix(int **matrix,int riga,int colonna);
void sumMatrix(int **matrix1,int **matrix2,int rig,int col);

main(){

  int **matrix1;
  int **matrix2;
  int rig1,col1,rig2,col2;

  readMatrix(&matrix1,&rig1,&col1);
  readMatrix(&matrix2,&rig2,&col2);

  if(rig1==rig2 && col1==col2)
    sumMatrix(matrix1,matrix2,rig1,col1);
  else{
    puts("Errore le matrici non sono conformi.");
    return;
  }

  puts("La matrice somma e` :");
  printMatrix(matrix1,rig1,col1);

}

void readMatrix(int ***matrix,int *rig,int *col){

  int x,y;
  
  puts("Inserire il numero di righe.");
  scanf("%d",rig);
  puts("Inserire il numero di colonne.");
  scanf("%d",col);

  //Alloco spazio per n (righe) puntatori a int.

  *matrix=(int **)calloc((*rig),sizeof(int *));

  //Alloco spazio per m (colonne) interi.

  for(x=0; x < (*rig); x++)
    *(*matrix+x)= (int *)calloc((*col),sizeof(int));

  //Leggo i singoli elementi della matrice.(x=riga y=colonna).

  for(x=0; x <(*rig); x++)
    for(y=0; y <(*col); y++){
      printf("Inserire l'elemento riga %d colonna %d\n",x,y);
      scanf("%d",&((*matrix)[x][y]));
    }
  
}

void printMatrix(int **matrix,int riga,int colonna){

  int x,y;

  for(x=0; x<riga; x++){
    for(y=0; y<colonna; y++)
      printf("%d\t",matrix[x][y]);
    printf("\n");
  }

}

void sumMatrix(int **matrix1,int **matrix2,int rig,int col){

  int x,y;

  for(x=0; x<rig; x++)
    for(y=0; y<col; y++)
      *((*((matrix1)+x))+y) = (*((*((matrix1)+x))+y) + *((*((matrix2)+x))+y));

}
