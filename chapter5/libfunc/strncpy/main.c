#include <stdio.h>

char* strncpy_(char* s, char* t, int n);

int main() {
  char *s = "ahmed";
  char t[6];
  char* temp = strncpy_(t, s, 6);

  printf("%s\n", temp);
}

char* strncpy_(char* s, char* t, int n) {
  char* dst = s;
  
  while(--n >= 0) {
    *s = *t;
    ++s;
    ++t;
  }

  return dst;
}
