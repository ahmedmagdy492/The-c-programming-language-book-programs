#include <stdio.h>
#include <string.h>

int atoi_(char*);

int main() {
  char s[10];
  memset(s, 0, 10);
  memcpy(s, "456", 4);
  
  int result = atoi_(s);

  printf("%d\n", result);
}

int atoi_(char* s) {
  int result = 0;
  
  while(*s != '\0') {
    result = result*10 + (*s - '0');
    ++s;
  }

  return result;
}
