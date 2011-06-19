#include<stdio.h>
#include<stdlib.h>

void readVet(int **vett,int *rig);
void printMatrix(int **matrix,int riga,int colonna);
int ** convDiagonal(int *vett,int rig);

main(){

  int *vett;
  int rig;
  int **diagonalM;

  puts("Dati del vettore da convertire in matrice diagonale.");

  //Passo l'indirizzo del puntatore a int altrimenti le modifiche non erano riportate nel main.
  readVet(&vett,&rig);
  
  diagonalM = convDiagonal(vett,rig);

  puts("La matrice diagonale risultante e` :");
  printMatrix(diagonalM,rig,rig);

}

void readVet(int **vett,int *rig){

  int x;
  
  puts("Inserire il numero di righe.");
  scanf("%d",rig);

  *vett = (int *) calloc(*rig,sizeof(int));

  for(x=0; x<(*rig); x++){
    printf("Inserire l'elemento %d\n",x);
    scanf("%d",&(*vett)[x]);
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

int ** convDiagonal(int *vett,int rig){

  int x;
  int **matrix;

  //Alloco spazio per la matrice quadrata da riempire.
  
  matrix = (int **)calloc(rig,sizeof(int *));
  for(x=0; x<rig; x++)
    *(matrix+x) = (int *)calloc(rig,sizeof(int));

  //Riempie la matrice.

  for(x=0; x<rig; x++)
    *((*(matrix+x))+x) = vett[x];

  return matrix;

}
