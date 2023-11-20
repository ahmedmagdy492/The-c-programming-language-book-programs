#include <stdio.h>
#include <string.h>

void revstr(char[], int);

int main() {
  char s[] = "mona mona";
  revstr(s, strlen(s));
  printf("%s\n", s);
}

void revstr(char s[], int len) {
  static int i = 0;

  if(i == (len-1)) {
    return;
  }
  char temp = s[i];
  s[i] = s[len-1];
  s[len-1] = temp;
  ++i;
  revstr(s, len-1);
}
