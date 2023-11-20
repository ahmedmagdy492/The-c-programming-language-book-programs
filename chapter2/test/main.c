#include <stdio.h>
#include <limits.h>

int main() {
  // char
  printf("signed char ranges from %d to %d\n", SCHAR_MIN, SCHAR_MAX);
  printf("unsigned char range from 0 to %d\n", UCHAR_MAX);

  // short
  printf("signed short ranges from %d to %d\n", SHRT_MIN, SHRT_MAX);
  printf("unsigned short ranges from 0 to %d\n", USHRT_MAX);

  // int
  printf("signed int ranges from %d to %d\n", INT_MIN, INT_MAX);
  printf("unsigned int ranges from 0 to %ld\n", UINT_MAX);

  // long
  printf("signed long ranges from %ld to %ld\n", LONG_MIN, LONG_MAX);
  printf("unsigned long ranges from 0 to %llu\n", ULONG_MAX);
}
