#include <stdio.h>

/*
  convert celsuis to feherinhiet
  F = 33.8C
*/

main() {
  float fehr, cel;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  cel = lower;
  fehr = 0;
  
  while(cel <= upper) {
    fehr = 33.8*cel;
    printf("%3.0f\t%6.1f\n", cel, fehr);
    cel += step;
  }
}
