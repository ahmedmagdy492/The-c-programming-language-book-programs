#include <stdio.h>
#include <string.h>

void strcat_(char* s, char* t);

int main() {
  char name[10] = {'a', 'h', 'm', 'e', 'd', '\0'};
  char new[3] = {'a', 'm', '\0'};

  strcat_(name, new);

  printf("%s\n", name);
}

void strcat_(char* s, char* t) {
  s = s + strlen(s);

  while(*s++ = *t++)

  *s = '\0';
}
