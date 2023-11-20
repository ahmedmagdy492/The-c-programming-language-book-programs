#include <stdio.h>
#include <string.h>

int strncmp_(char* s, char* t, int n);

int main() {
  char name[] = "ahmed";
  char name2[] = "ahme";

  printf("%d\n", strncmp_(name, name2, 4));
}

int strncmp_(char* s, char* t, int n) {
  while(--n >= 0) {
    if(*s != *t || *s == '\0') {
      return *s - *t;
    }
    s++;
    t++;
  }

  return 0;
}
