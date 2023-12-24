#pragma once

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "types.h"

struct Node {
  WordRef word;
  struct Node* right;
  struct Node* left;
};

typedef struct Node Node;

Node* addtree(char* word, int word_start_index, Node* root) {
  if(root == NULL) {
    root = (Node*)malloc(sizeof(Node));
    memset(&(root->word), 0, sizeof(root->word));
    
    memcpy(root->word.word, word, strlen(word));
    root->left = NULL;
    root->right = NULL;
    root->word.indexes[root->word.cur_index++] = word_start_index;
    return root;
  }
  else {
    int cond;
    if((cond = strcmp(word, root->word.word)) == 0) {
      root->word.indexes[root->word.cur_index++] = word_start_index;
    }
    else if(cond < 0){
      root->left = addtree(word, word_start_index, root->left);
    }
    else {
      root->right = addtree(word, word_start_index, root->right);
    }
    return root;
  }
}

void traverse_tree(Node* root) {
  if(root != NULL) {
    traverse_tree(root->left);
    printf("word = %s:\n", root->word.word);
    int i;
    for(i = 0; i < root->word.cur_index; ++i) {
      printf("\tindex = %d\n", root->word.indexes[i]);
    }
    traverse_tree(root->right);
  }
}

void clear(Node* root) {
  if(root == NULL)
    return;

  clear(root->left);
  clear(root->right);
  free(root);
}
