#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NLINE 10
#define NNUM 100

int main() {
  int c, nchars = 0;
  char num_buf[NNUM], digit_count = 0;

  while((c = getchar()) != EOF) {
    if(c == '\n') {
      printf("%x", atoi(num_buf));
      digit_count = 0;
      memset(num_buf, 0, NNUM);
      nchars = 0;
    }
    if(nchars == NLINE) {
      printf("\n");
      nchars = 0;
    }
    if(!isdigit(c)) {
      printf("%c", c);
    }
    else {
      num_buf[digit_count++] = c;
    }
    ++nchars;
  }

  printf("\n");
}
