#include <stdio.h>

void printAsBinary(int number);
int setbits(unsigned int x, int p, int n, unsigned int y);

int main() {
  unsigned int x = 255;
  unsigned int y = 6;

  int r = setbits(x, 2, 4, y);
  printf("result = %d\n", r);
  printAsBinary(r);

  return 0;
}

// NOTE: we need to clear x first before combining the y bits
int setbits(unsigned int x, int p, int n, unsigned int y) {
  int mask = ~(~0 << n);
  unsigned int rightMostNBitsInY = y & mask;
  unsigned int xWithCleanedBits = x & ~(~(~0 << n) << (p+1-n));

  return xWithCleanedBits | (rightMostNBitsInY << (p+1-n));
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
