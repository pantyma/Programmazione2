/*
 * Traccia del 6 Maggio 2011
 * Prencipe Mattia
 */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>


#define MAXLENGHT 2048
#define MAXEXT 10

int dimTot=0;

int attraversaDir(char *pathName,char *ext);
void usage();

main(int argc,char *argv[])
{
  char pathName[MAXLENGHT];
  char ext[MAXEXT];

  switch(argc){
  case (1):
    strcpy(pathName,".");
    strcpy(ext,"*");
    break;
  case (2):
    strcpy(pathName,argv[1]);
    strcpy(ext,"*");
    break;
  case (3):
    strcpy(pathName,argv[1]);
    strcpy(ext,argv[2]);
    break;
  default :
    usage();
    return;
  }
  
  if(attraversaDir(pathName,ext)!=-1)
    printf("\nDimensione totale: %d\n",dimTot);
  //printf("pathName= %s e ext = %s\n",pathName,ext);
}

int attraversaDir(char *pathName,char *ext)
{
  struct dirent *sdp;
  DIR *drc;
  struct stat ssp;
  char name[MAXLENGHT];

  
  if((drc=opendir(pathName))==NULL)
    {
      perror("Error: la directory non puo` essere aperta.");
      return -1;
    }
  while((sdp=readdir(drc))!=NULL)
    {
      if((strcmp(sdp->d_name,".")==0) || (strcmp(sdp->d_name,"..")==0))
	continue;
      if((strlen(pathName)+strlen(sdp->d_name)+2)>sizeof(name))
	printf("Il pathname %s%s e` troppo lungo.\n",pathName,sdp->d_name);
      else
	{
	  sprintf(name,"%s/%s",pathName,sdp->d_name);
	  stat(name,&ssp);
	  if(ssp.st_mode & S_IFDIR)
	    {
	      printf("Directory %s\n",name);
	      attraversaDir(name,ext);
	    }
	  else
	    {
	      if(strcmp(ext,"*")!=0)
		{
		  if(strstr(sdp->d_name,ext)!=NULL)
		    {
		      printf("File %s  %d\n",name,(int)ssp.st_size);
		      dimTot=dimTot+((int)ssp.st_size);
		    }
		}
	      else
		{
		  printf("File %s  %d\n",name,(int)ssp.st_size);
		  dimTot=dimTot+((int)ssp.st_size);
		}
	    }
	}
    }
  closedir(drc);
}

void usage()
{
  printf("USAGE MYFIND:\n\n");
  printf("./myfind [pathName] [extent]\t Cerca ricorsivamente in pathName tutti i file con estensione extent\n\te li stampa affiancando la loro dimensione in byte. Alla fine restituisce il totale di byte contati.\n\n");
  printf("Se pathName e` omesso si parte dalla directory corrente e se extent e` omesso si considerano tutti i file.\n");
}
