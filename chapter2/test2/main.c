#include <stdio.h>
#include <string.h>

#define LIM 100

int main() {
  char buffer[LIM];
  int lim = LIM;
  int c;

  for(int i = 0; i < lim-1;++i) {
    if((c = getchar()) == '\n') {
      memset(buffer, 0, lim);
      i = 0;
    }
    else if (c == EOF){
      break;
    }
    else {
      buffer[i] = c;
    }
  }
}
