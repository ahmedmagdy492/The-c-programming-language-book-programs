#include <stdio.h>
#include <string.h>

int strend(char*, char*);

int main() {
  char* s = "ahmed";
  char* t = "1";

  printf("%d\n", strend(s, t));
}

int strend(char* s, char* t) {
  int tlen = strlen(t);

  if(tlen == 0)
    return 0;

 s = s + (strlen(s) - tlen);

  while(*t != '\0') {
    if(*s++ != *t++)
      return 0;
  }

  return 1;
}
