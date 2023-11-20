#include <stdio.h>
#include <string.h>

char* strncat_(char* s, char* t, int n);

int main() {
  char s[11] = {'a', 'h', 'm', 'e', 'd', '\0'};
  char t[] = "lllll";

  char* temp = strncat_(s, t, 2);

  printf("%s\n", temp);
}

char* strncat_(char* s, char* t, int n) {
  char* dst = s;
  s = s + strlen(s);

  while(--n >= 0) {
    *s = *t;
    ++s;
    ++t;
  }

  return dst;
}
