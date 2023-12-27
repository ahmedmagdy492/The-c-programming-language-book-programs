#pragma once

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define NCHARS 100

struct WordCount {
  char word[NCHARS];
  int count;
};

struct Node {
  struct WordCount word_count;
  struct Node* right;
  struct Node* left;
};

typedef struct Node Node;

Node* addtree(struct WordCount* word_count, Node* root) {
  if(root == NULL) {
    root = (Node*)malloc(sizeof(Node));
    memcpy(root->word_count.word, word_count->word, strlen(word_count->word));
    root->left = NULL;
    root->right = NULL;
    root->word_count.count = word_count->count;
    return root;
  }
  else {
    if(strcmp(root->word_count.word, word_count->word) == 0) {
      return root;
    }
    else if(root->word_count.count < word_count->count) {
      root->left = addtree(word_count, root->left);
    }
    else {
      root->right = addtree(word_count, root->right);
    }
    return root;
  }
}

void traverse_tree(Node* root) {
  if(root != NULL) {
    traverse_tree(root->left);
    printf("word = %s, count = %d\n", root->word_count.word, root->word_count.count);
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
