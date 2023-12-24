#include <stdio.h>
#include "extract_word.h"
#include "bin_tree.h"
#define MAX_WORD_LEN 1000

int main(int argc, char** argv) {
  if(argc == 2) {
    char word[MAX_WORD_LEN], word_start_index = 0;
    Node* root = NULL;
    while((word_start_index = extract_next_word(argv[1], word)) != EOF) {
      root = addtree(word, word_start_index, root);
    }
    traverse_tree(root);
  }
  else {
    printf("Usage: %s <str>\n", argv[0]);
    return 1;
  }

  return 0;
}
