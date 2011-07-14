#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<sys/stat.h>

void permissions(unsigned int perms,char *p);

int main(int argc, char **argv)
{

  DIR *d;
  struct dirent *de;
  struct stat sfile;
  char strperms[10];
  
  if(argc==2)
    {
      if(d=opendir(argv[1]))
	{

	  while((de=readdir(d))!=NULL)
	    {
	      stat(de->d_name,&sfile);
	      permissions(sfile.st_mode,strperms);
	      printf("%s\t%s\n",strperms,de->d_name);
	    }
	  closedir(d);
	  
	}else{
	  perror(argv[1]);
	  exit(2);
	}
      
    }else
    fprintf(stderr,"Syntax: ls dirname\n");
}


void permissions(unsigned int perms,char *p)
{

  char pletter[]={'r','w','x'};
  int x,y;
  
  p[9]='\0';
  
  for(y=2;y>=0;y--)
    for(x=2;x>=0;x--)
      {
	char c;
	if(perms & 01)
	  p[y*3+x]=pletter[x];
	else
	  p[y*3+x]='-';
	perms>>=1;
      }
  
}
