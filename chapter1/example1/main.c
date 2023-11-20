#include <stdio.h>

int main() {
  float fehr, cel;
  int lower, step, upper;

  fehr = 0;
  cel = 0;
  step = 20;
  lower = 0;
  upper = 300;

  printf("Fehr \t Cel\n");

  while(fehr <= upper) {
    cel = (5.0/9.0)*(fehr-32.0);
    printf("%4.0f\t%6.1f\n", fehr, cel);
    fehr += step;
  }
}
