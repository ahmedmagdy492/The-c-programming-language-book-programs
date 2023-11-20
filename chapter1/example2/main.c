#include <stdio.h>

main() {
  int fehr;

  for(fehr = 300;fehr >= 0; fehr -= 20) {
    printf("%3d\t%6.1f\n", fehr, (5.0/9.0)*(fehr-32));
  }
}
