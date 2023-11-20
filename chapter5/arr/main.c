#include <stdio.h>


int strlen_(char *s);

int main() {

  char s[] = "ahmed";

  //printf("%d\n", strlen_(s+2));
  printf("%c\n", (s+2)[-1]);
}

int strlen_(char s[]) {
  int i = 0;
  
  while((*s) != '\0') {
    ++s;
    ++i;
  }

  return i;
}
