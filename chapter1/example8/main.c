#include <stdio.h>
#define COUNT 10

main() {
  int bc, lc, tc, i;
  int digits[COUNT];

  digits[0] = ' ';
  digits[1] = '\n';
  digits[2] = ' ';
  digits[3] = '\t';
  digits[4] = '\t';
  digits[5] = '\n';

  bc = lc = tc = 0;

  for(i = 0; i < COUNT;++i) {
    if(digits[i] == ' ') {
      ++bc;
    }
    else if(digits[i] == '\t') {
      ++tc;
    }
    else if(digits[i] == '\n') {
      ++lc;
    }
  }

  printf("blank count: %d, tab count: %d, line count: %d\n", bc, tc, lc);
}
