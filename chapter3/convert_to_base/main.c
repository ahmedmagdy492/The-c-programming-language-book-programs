#include <stdio.h>
#include <string.h>

void rev(char s[]);

void itob(int n, char s[], int b);

int main() {
  int n = 0xF;
  char s[3];

  itob(n, s, 10);

  printf("%s\n", s);
}

void itob(int n, char s[], int b) {

  int counter = 0;

  do {
    if(b == 16 && n > 9)
      s[counter++] = (n % b) + 'A' - 10;
    else
      s[counter++] = (n % b) + '0';
  } 
  while((n /= b) > 0);

  s[counter] = '\0';

  rev(s);
}

void rev(char s[]) {
  int i = 0, j = strlen(s)-1;

  for(; i < j; ++i, --j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}
