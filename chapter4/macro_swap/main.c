#include <stdio.h>

#define swap(t, x, y) {t temp = x; x = y; y = temp;}
//#undef swap

int main() {
  int x = 2, y = 34;
  swap(int, x, y);

  printf("x = %d, y = %d\n", x, y);
}
