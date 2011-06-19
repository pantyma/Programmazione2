#include<stdio.h>
#include<stdlib.h>

//Miglioramenti: si puo` gestire l'errore dovuto all'inserimento di caratteri.

void readMatrix(int ***matrix,int *rig,int *col);
void printMatrix(int **matrix,int riga,int colonna);
int ** trasposta(int **matrix1,int rig,int col);

main(){

  int **matrix;
  int **matrixTr;
  int rig,col;
  
  puts("Funzione trasposta di una matrice data.");
  readMatrix(&matrix,&rig,&col);

  matrixTr = trasposta(matrix,rig,col);
  
  puts("La matrice data e` :");
  printMatrix(matrix,rig,col);
  puts("La corrispondente trasposta e` :");
  printMatrix(matrixTr,col,rig);
  
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

int ** trasposta(int **matrix,int rig,int col){

  int x,y;
  int **matrixTr;

  //Alloco spazio per una matrice con rig e col opposta a quella data.
  //Alloco spazio per col (righe) puntatori a int.

  matrixTr = (int **)calloc(col,sizeof(int *));

  //Alloco spazio per rig (colonne) interi.

  for(x=0; x < col; x++)
    *(matrixTr+x)= (int *)calloc(rig,sizeof(int));

  //Procedo con la trasposta.
  
  for(x=0; x<col; x++)
    for(y=0; y<rig; y++)
      *((*(matrixTr+x))+y) = (*((*(matrix+y))+x));

  return matrixTr;

}
