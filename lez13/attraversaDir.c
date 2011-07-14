/* Programma preso dai lucidi stampa tutte le directory presenti nel path passato.*/

#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include <sys/stat.h>
#include<sys/types.h>

void dirwalk(char *dir, void (*fcn)(char *));
void recprint(char *name);

#define MAX_PATH 1024
#define INDENTATION 2

int main(int argc, char **argv)
{
  if(argc==2)
    dirwalk(argv[1],(void *) (&recprint));
}

void dirwalk(char *dir, void (*fcn)(char *))
{
  char name[MAX_PATH];
  struct dirent *dp;
  DIR *dfd;
  
  if ((dfd = opendir(dir)) == NULL) {
    fprintf(stderr, "dirwalk: can't open %s\n", dir);
    return;
  }
  while ((dp = readdir(dfd)) != NULL) {
    if (strcmp(dp->d_name, ".") ==0 || strcmp(dp->d_name, "..")==0 || strcmp(dp->d_name,".git")==0)
      continue; /* skip self and parent */
    if (strlen(dir)+strlen(dp->d_name)+2 > sizeof(name))
      fprintf(stderr, "dirwalk: name %s %s too long\n", dir, dp->d_name);
    else {
      sprintf(name, "%s/%s", dir, dp->d_name);
      (*fcn)(name);
    }
  }
  closedir(dfd);
}

void recprint(char *name){
  struct stat fsbuf;
 
  stat(name, &fsbuf);
  if(fsbuf.st_mode & S_IFDIR)
    {
      printf("%s\n",name);
      //strcat(name,"/");
      dirwalk(name,(void *)(& recprint));
    }else{
    printf("%s  %d\n",name,(int)fsbuf.st_size);
  }
}
