#include <stdio.h>

void rev(char s[], int len);


int main() {
  char s[] = "ahmed";

  rev(s, 5);

  printf("%s\n", s);
}

void rev(char s[], int len) {
  int i, j;

  for(i = 0, j = len-1; i <= j; ++i, --j) {
    int temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}
