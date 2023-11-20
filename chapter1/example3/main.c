#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

main() {
  int fehr;

  for(fehr = UPPER;fehr >= LOWER; fehr -= STEP) {
    printf("%3d\t%6.1f\n", fehr, (5.0/9.0)*(fehr-32));
  }
}
