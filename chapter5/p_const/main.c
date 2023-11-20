#include <stdio.h>

void swap(int*, int*);

int main(void) {
  int a = 12;
  int b = 44;

  printf("a = %d, b = %d\n", a, b);

  swap(&a, &b);

  printf("a = %d, b = %d\n", a, b);
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
