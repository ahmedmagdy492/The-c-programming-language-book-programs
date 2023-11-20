#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void unescape(char s[], char t[]);

int main() {
  char s[] = "ahmed magdy\tahmed\t\n\t";
  char *t = (char*)malloc(sizeof(char)* strlen(s)+1);
  memset(t, 0, strlen(s)+1);
  
  unescape(s, t);

  printf("%s\n", t);

  free(t);
}

void unescape(char s[], char t[]) {
  int i = 0, j = 0;
  while(s[i] != '\0') {
    if(s[i] == '\\' && s[i+1] == 'n') {
      t[j] = '\n';
      ++j;
    }
    else if (s[i] == '\\' && s[i+1] == 't') {
      t[j] = '\t';
      ++j;
    }
    else {
      t[j] = s[i];
      ++j;
    }
    ++i;
  }
}
