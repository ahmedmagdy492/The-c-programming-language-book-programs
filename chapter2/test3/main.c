#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int atoi_2(char s[]) {
  int n, i;

  n = 0;
  for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
    n = n * 10 + (s[i] - '0');
  }

  return n;
}

int main(int argc, char** argv) {
  /*long value = -1;
    printf("%u\n", value);*/
  int value = 100;
  int result = sqrt(value);

  printf("%d\n", result);
  
}
