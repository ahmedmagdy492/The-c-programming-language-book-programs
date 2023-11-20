#include <stdio.h>
#define MAX_LINE 1000

int getlin(char*);

int main() {
  char s[MAX_LINE];

  int result = getlin(s);

  printf("%s", s);
}

int getlin(char* s) {
  int c;
  
  while((c = getchar()) != EOF && c != '\0') {
    *s++ = c;
  }

  return c;
}
