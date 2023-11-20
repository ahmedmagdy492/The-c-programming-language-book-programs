#include <stdio.h>
#include <string.h>
#define MAX_WORD_SIZE 100
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

void show_histogram(char word[], int count) {
  static int x = 0;
  int i;

  gotoxy(x, 0);

  for(i = 0; i < count; ++i) {
    printf("_\n");
  }

  for(i = 0; i < count; ++i) {
    printf("%c\n", word[i]);
  }

  ++x;
}

main() {
  int c, isInWord, cc;
  char word[MAX_WORD_SIZE];

  memset(word, 0, MAX_WORD_SIZE);

  isInWord = 0;
  cc = 0;

  while((c = getchar()) != EOF) {
    if(c == ' ' || c == '\n' || c == '\t') {
      show_histogram(word, cc);
      cc = 0;
      isInWord = 0;
      memset(word, 0, MAX_WORD_SIZE);
    }
    else {
      isInWord = 1;
      word[cc] = c;
      ++cc;
    }
  }
}
