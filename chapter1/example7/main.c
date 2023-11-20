#include <stdio.h>
#include <string.h>
#define MAX_WORD_LEN 100

main() {
  int isInWord;
  int c, wc, lc, cc, counter;
  char current_word[MAX_WORD_LEN];

  memset(current_word, 0, MAX_WORD_LEN);

  counter = 0;
  isInWord = 0;
  wc = lc = cc = 0;

  while((c = getchar()) != EOF) {
    ++cc;
    if(c != ' ' && c != '\n' && c != '\t') {
      isInWord = 1;
      current_word[counter] = c;
      ++counter;
    }
    else {
      if(isInWord) {
	++wc;
	isInWord = 0;
	printf("%s\n", current_word);
	memset(current_word, 0, MAX_WORD_LEN);
	counter = 0;
      }

      if(c == '\n') {
	++lc;
      }
    }
  }

  printf("chars: %d, lines count: %d, words: %d\n", cc, lc, wc);
}
