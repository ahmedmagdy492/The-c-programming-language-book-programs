#include <stdio.h>
#include <ctype.h>
#include "getch.h"
#define LEN 100

int main() {
  int n, getfloat(float*);
  float array[LEN];

  for(n = 0; n < LEN && (getfloat(&array[n]) != EOF); ++n)
    ;

  for(n = 0; n < LEN; ++n) {
    if(array[n] != 0) {
      printf("%f\n", array[n]);
    }
  }
}

int getfloat(float* pn) {
  int c, sign, d, nf;
  
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

  if(c == '.') {
    for(nf = 1; isdigit(c = getch()); nf*=10)
      *pn = 10*(*pn) + (c - '0');
    *pn = *pn / nf;
  }

  *pn *= sign;
  if(c != EOF)
    ungetch(c);
  return c;
}
