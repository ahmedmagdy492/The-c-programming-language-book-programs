#include <stdio.h>

int bit_count(int x);

int main() {
  int x = 0;
  //int result = bit_count(x);
  int result = x - 1;

  printf("%d\n", result);
}

int bit_count(int x) {
  int i, count;
  i = 1;
  int variable_len = sizeof(int) * 8, total_set_bits = 0;

  for(count = 0; count < variable_len; ++count) {
    if ((x & i)) {
      ++total_set_bits;
    }
    i <<= 1;
  }

  return total_set_bits;
}
