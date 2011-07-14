#ifndef PARSE_H
#define PARSE_H

#define CHARLEN 80
#define NUMPAR 20

typedef struct cmdline{

  char command[CHARLEN];
  char param[NUMPAR][CHARLEN];
  int numpar;
  char inFile[CHARLEN];
  char outFile[CHARLEN];
  char errFile[CHARLEN];
  int background;

}tcmdline;

tcmdline parseLine(char *line);

#endif
