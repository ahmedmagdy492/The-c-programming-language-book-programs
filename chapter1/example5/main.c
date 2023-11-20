#include <stdio.h>

int main() {
  int c;
  int count;
  count = 0;

  while((c = getchar()) != EOF) {
    count++;
  }

  printf("characters entered: %d\n", count);
}
