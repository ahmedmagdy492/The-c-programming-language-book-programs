#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void escape(char s[], char t[]);

int main() {
  char s[] = "ahmed magdy	\nahmed\t\n\t";
  char *t = (char*)malloc(sizeof(char)*strlen(s)+6);

  escape(s, t);

  printf("%s\n", t);

  free(t);
}

void escape(char s[], char t[]) {
  int i = 0, j = 0;

  while(s[i] != '\0') {
    switch(s[i]) {
    case '\t':
      t[j] = '\\';
      ++j;
      t[j] = 't';
      ++j;
      break;
    case '\n':
      t[j] = '\\';
      ++j;
      t[j] = 'n';
      ++j;
      break;
    default:
      t[j] = s[i];
      ++j;
      break;
    }

    ++i;
  }
}
