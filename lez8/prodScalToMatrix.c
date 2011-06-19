#include<stdio.h>
#include<stdlib.h>

void readMatrix(int ***matrix,int *rig,int *col);
void printMatrix(int **matrix,int riga,int colonna);
void prodScalToMatrix(int scal,int **matrix,int rig,int col);

main(){

  int **matrix;
  int scal;
  int rig,col;

  puts("Inserire uno scalare.");
  scanf("%d",&scal);
  readMatrix(&matrix,&rig,&col);

  prodScalToMatrix(scal,matrix,rig,col);

  puts("Il prodotto dello scalare per la matrice e` :");
  printMatrix(matrix,rig,col);

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

void prodScalToMatrix(int scal,int **matrix,int rig,int col){

  int x,y;

  for(x=0; x<rig; x++)
    for(y=0; y<col; y++)
      *((*(matrix+x))+y) = (*((*(matrix+x))+y) * scal);

}
