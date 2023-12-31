#include <stdio.h>
#include <ctype.h>
#include "calc.h"
#define BUFSIZE 100

int getop(char s[]) {
  int i, c;
  static int lastc = 0;

  if(lastc == 0) {
    lastc = getch();
  }
  else {
    c = lastc;
  }

  while((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if(!isdigit(c) && c != '.')
    return c;
  i = 0;
  if(isdigit(c))
    while(isdigit(s[++i] = c = getch()))
      ;
  if(c == '.')
    while(isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if(c != EOF)
    lastc = c;
  return NUMBER;
}
