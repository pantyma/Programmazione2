#include<stdio.h>
#include<stdlib.h>

//Miglioramenti: si puo` gestire l'errore dovuto all'inserimento di caratteri.

void readMatrix(int ***matrix,int *rig,int *col);
void printMatrix(int **matrix,int riga,int colonna);
int ** prodOfMatrix(int **matrix1,int **matrix2,int rig1,int rig2,int col2);

main(){

  int **matrix1;
  int **matrix2;
  int **matrixResult;
  int rig1,col1,rig2,col2;

  puts("Inserire i dati della prima matrice.");
  readMatrix(&matrix1,&rig1,&col1);
  puts("Inserire i dati della seconda matrice.");
  readMatrix(&matrix2,&rig2,&col2);

  if(col1==rig2)
    matrixResult=prodOfMatrix(matrix1,matrix2,rig1,rig2,col2);
  else{
    puts("Error: le matrici non sono conformi.");
    return;
  }

  puts("Il prodotto delle due matrici e` :");
  printMatrix(matrixResult,rig1,col2);

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

//Le colonne della prima matrice sono uguali alle righe della seconda matrice.(col1=rig2)

int ** prodOfMatrix(int **matrix1,int **matrix2,int rig1,int rig2,int col2){

  int x,y,z;
  int temp=0;
  int **matrixResult;

  //Alloco spazio per rig1 puntatori a int.
  matrixResult=(int **)calloc(rig1,sizeof(int *));

  //Per ogni riga alloco spazio per col2 colonne di interi.
  for(x=0; x < rig1; x++)
    *(matrixResult+x)= (int *)calloc(col2,sizeof(int)); 

  for(x=0; x<rig1; x++)
    for(y=0; y<col2; y++){
      for(z=0; z<rig2; z++)
	temp += ( (*((*(matrix1+x))+z)) * (*((*(matrix2+z))+y)) );
      *((*( matrixResult+x))+y) = temp;
      temp=0;
    }

  return matrixResult;
}
