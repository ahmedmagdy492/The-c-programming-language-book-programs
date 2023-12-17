#include <stdio.h>

#include "types.h"
#include "binary_search.h"
#include "extract_word.h"
#define NCHARS 100

int main(int argc, char* argv[]) {
  if(argc == 2) {
    char current_word[NCHARS];
    while(extract_next_word(argv[1], current_word) != NULL) {
      int keyword_index = bin_search(keywords, 0, NKEY, current_word);
      if(keyword_index != -1) {
	keywords[keyword_index].count += 1;
      }
    }

    // printing out the result
    int i;

    for(i = 0; i < NKEY; ++i) {
      printf("%s => %d\n", keywords[i].word, keywords[i].count);
    }
  }
  else {
    printf("Usage: %s <str-input>\n", argv[0]);
  }
}
