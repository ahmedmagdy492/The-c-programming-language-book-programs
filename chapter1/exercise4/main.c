#include <stdio.h>

main() {
  int nc, nl, nb, c;

  nc = 0;
  nl = 0;
  nb = 0;

  while((c = getchar()) != EOF) {
    ++nc;
    if(c == '\n')
      ++nl;
    if(c == ' ' || c == '\t')
      ++nb;
  }

  printf("characters: %d, lines: %d, blanks: %d\n", nc, nl, nb);
}
