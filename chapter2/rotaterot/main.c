#include <stdio.h>

unsigned int rotaterot(unsigned x, int n);

int main() {
  unsigned int x = 15;

  unsigned int result = rotaterot(x, 6);

}

unsigned int rotaterot(unsigned x, int n) {
  unsigned int extractedFirstNBitsFromX = x & ~(~0 << n);
  int result = extractedFirstNBitsFromX << (sizeof(unsigned int)*8 - n);
  x = x >> n;
  return result | x;
}
