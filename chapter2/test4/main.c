#include <stdio.h>

void squeeze(char s[], char c);

int main() {
  int c = 'h';
  char s[] = "ahmed";
  squeeze(s, c);

  printf("%s\n", s); 
}

void squeeze(char s[], char c) {
  int i, j;
  j = 0;

  for(i = 0;s[i] != '\0'; ++i) {
    if(s[i] != c) {
      s[j++] = s[i];
    }
  }

  s[j] = '\0';
}
