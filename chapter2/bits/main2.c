#include <stdio.h>

void printAsBinary(int number);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
  unsigned int x = 255;
  unsigned int y = 6;

  int r = setbits(x, 2, 4, y);
  printf("result = %d\n", r);
  printAsBinary(r);

  return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  return x & ~(~(~0 << n) << (p+1-n)) | (y & ~(~0 << n)) << (p+1-n);
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
