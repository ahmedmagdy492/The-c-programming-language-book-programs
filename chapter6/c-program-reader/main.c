#include <stdio.h>
#include <string.h>

#include "extract_word.h"
#include "bin_tree.h"
#define MAX_WORD 1000

int main(int argc, char** argv) {
  if(argc == 2) {
    char word[MAX_WORD];
    Node* root = NULL;
    
    while(extract_next_word(argv[1], word) != NULL) {
      if(isalpha(word[0]) && strlen(word))
	root = addtree(word, root);
    }
    traverse_tree(root);
    clear(root);
  }
  else {
    printf("Usage: %s <c program>\n", argv[0]);
    return 1;
  }

  return 0;
}
