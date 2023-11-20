#include <stdio.h>

int main() {
  int wc, oc, dc;
  int c;

  wc = dc = oc = 0;

  while((c = getchar()) != EOF) {
    switch(c) {
    case ' ':
    case '\t':
    case '\n':
      ++wc;
      break;
    case '0': case '1': case '2': case '3': case '4': case '5':
    case '6': case '7': case '8': case '9':
      ++dc;
      break;
    default:
      ++oc;
      break;
    }
  }

  printf("whitespace = %d, digits = %d, chars = %d\n", wc, dc, oc);
}
