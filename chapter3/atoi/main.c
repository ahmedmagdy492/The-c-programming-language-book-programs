#include <stdio.h>
#include <string.h>

int toint(char s[], int isNeg);

int main() {
  char* num = "1232";
  int result = toint(num, 1);
  printf("%d\n", result);
}

int toint(char s[], int isNeg) {
  int i = 0, number = 0, len = strlen(s)-1, j = 0, value = 1;

  for(; j < len; ++j) {
    value *= 10;
  }

  while(s[i] != '\0') {
    number += value*(s[i] - '0');
    ++i;
    value /= 10;
  }

  return isNeg ? (number*-1) : number;
}
