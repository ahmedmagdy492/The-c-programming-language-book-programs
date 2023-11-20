#include <stdio.h>

void itoa_(int, char[]);

int main() {
  char s[4];
  itoa_(123, s);

  printf("%s\n", s);
}

void itoa_(int n, char s[]) {
  int reminder;
  static int i = 0;

  if(n > 0) {
    reminder = n % 10;
    n /= 10;
    itoa_(n, s);
    s[i++] = '0' + reminder;
  }
  else {
    s[i] = '\0';
  }
}
