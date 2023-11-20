#include <stdio.h>
#include <ctype.h>
#include "getch.h"
#define LEN 10

int main() {
  int n, array[LEN], getint(int*);

  for(n = 0; n < LEN; ++n)
    array[n] = -111;

  for(n = 0; n < LEN && (getint(&array[n]) != EOF); ++n)
    ;

  for(n = 0; n < LEN; ++n) {
    if(array[n] != -111) {
      printf("%d\n", array[n]);
    }
  }
}

int getint(int* pn) {
  int c, sign, d;
  
  while(isspace(c = getch()))
    ;

  if(!isdigit(c) && c != '+' && c != '-' && c != EOF) {
    ungetch(c);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;
  if(c == '-' || c == '+') {
    d = c;
    if(!isdigit(c = getch())) {
      if(c != EOF)
	ungetch(c);
      ungetch(d);
      return d;
    }
  }

  for(*pn = 0; isdigit(c); c = getch()) {
    *pn = 10*(*pn) + (c - '0');
  }

  *pn *= sign;
  if(c != EOF)
    ungetch(c);
  return c;
}
