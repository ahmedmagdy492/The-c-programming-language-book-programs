#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char** argv) {
  int c;

  while((c = getchar()) != EOF) {
    if(strstr(argv[0], "lower") != NULL) {
      putchar(tolower(c));
    }
    else if(strstr(argv[0], "upper") != NULL) {
      putchar(toupper(c));
    }
  }

  return 0;
}
