#include<stdio.h>
#include<stdlib.h>

//Miglioramenti: si puo` gestire l'errore dovuto all'inserimento di caratteri.

void readMatrix(int ***matrix,int *rig,int *col);
void printMatrix(int **matrix,int riga,int colonna);
void prodVetToMatrix(int **vet,int **matrix,int rigV,int rig);

main(){

  int **matrix;
  int **vettore;
  int rig=0,col=0,rigV=0,colV;

  colV=1;
  puts("Inserire i dati della matrice.");
  readMatrix(&matrix,&rig,&col);
  puts("Inserire i dati del vettore.");
  readMatrix(&vettore,&rigV,&colV);

  if(rigV==col)
    prodVetToMatrix(vettore,matrix,rigV,rig);
  else{
    puts("Error: le matrici non sono conformi.");
    return;
  }

  puts("Il prodotto del vettore per la matrice e` :");
  printMatrix(matrix,rig,col);

}

void readMatrix(int ***matrix,int *rig,int *col){

  int x,y;
  
  puts("Inserire il numero di righe.");
  scanf("%d",rig);
  if(*col==0){
    puts("Inserire il numero di colonne.");
    scanf("%d",col);
  }

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

//Le righe del vettore sono uguali alle colonne della matrice.(rigV=col)

void prodVetToMatrix(int **vet,int **matrix,int rigV,int rig){

  int x,y,z;
  int temp=0;

  for(x=0; x<rigV; x++)
    for(y=0; y<rigV; y++){
      for(z=0; z<rig; z++)
	temp += ( *(*(vet+x)) * (*((*(matrix+z))+y)) );
      *((*( matrix+x))+y) = temp;
    }

}
