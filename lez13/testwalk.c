#include <ftw.h>
#include <stdio.h>
#include<string.h>
#include <sys/stat.h>

int list(const char *name, const struct stat *status, int type);

int main(int argc, char *argv[]) {
  if(argc == 1)
    ftw(".", list, 1);
  else
    ftw(argv[1], list, 1);

  return 0;
}

int list(const char *name, const struct stat *status, int type) {
  if(type == FTW_NS)
    return 0;
  if(strstr(name,".git")!=NULL)
    return 0;

  if(type == FTW_F)
    printf("0%3o\t\t%s\n", status->st_mode, name);
 
  if(type == FTW_D && strcmp(".", name) != 0)
    printf("0%3o\t\t%s/\n", status->st_mode, name);

  return 0;
}
