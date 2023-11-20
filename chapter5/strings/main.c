#include <stdio.h>

void astrcpy(char* s, char* t);
int astrcmp(char*, char*);

int main() {
  char* name = "ahmedd";
  char* name2 = "ahmed";

  printf("%d\n", astrcmp(name, name2));
}

int astrcmp(char* s, char* t) {

  for(; *s == *t; ++s, ++t) {
    if(*s == '\0')
      return 0;
  }

  return *s - *t;
}

void astrcpy(char* s, char* t) {
  while((*s = *t) != '\0') {
    ++s;
    ++t;
  }
}
