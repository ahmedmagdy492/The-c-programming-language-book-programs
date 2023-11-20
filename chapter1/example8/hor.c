#include <stdio.h>
#include <string.h>
#define MAX_WORD_SIZE 100

void show_histogram(char word[], int count) {
  int i;

  printf("%15s ", word);

  for(i = 0; i < count; ++i) {
    printf("|");
  }

  printf("\n");
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
