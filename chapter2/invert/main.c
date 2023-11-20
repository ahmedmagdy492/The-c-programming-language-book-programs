#include <stdio.h>

void printAsBinary(int decimal_num);
unsigned int invert(unsigned x, int p, int n);

int main() {
  unsigned int x = 15;

  unsigned int result = invert(x, 8, 1);
  //printAsBinary(result);
}

unsigned int invert(unsigned x, int p, int n) {
  return x ^ (~(~0 << n) << p-1);
}

void printAsBinary(int decimal_num) {
  int binary_num, i, remainder;
  binary_num = 0, i = 1;
  while (decimal_num != 0) {
      remainder = decimal_num % 2;
      decimal_num /= 2;
      binary_num += remainder * i;
      i *= 10;
  }

  printf("%d\n", binary_num);
}
