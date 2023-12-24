#pragma once

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define NCHARS 1000
#define MAX_CHARS_TO_CHECK 6
#define min(x, y) (x > y ? y : x)

struct Node {
  char word[NCHARS];
  int count;
  struct Node* right;
  struct Node* left;
};

typedef struct Node Node;

Node* addtree(char* word, Node* root) {
  if(root == NULL) {
    root = (Node*)malloc(sizeof(Node));
    memcpy(root->word, word, strlen(word));
    root->left = NULL;
    root->right = NULL;
    root->count = 1;
    return root;
  }
  else {
    int cond;
    if((cond = strncmp(word, root->word, min(MAX_CHARS_TO_CHECK, strlen(root->word)))) == 0) {
      root->count++;
    }
    else if(cond < 0){
      root->left = addtree(word, root->left);
    }
    else {
      root->right = addtree(word, root->right);
    }
    return root;
  }
}

void traverse_tree(Node* root) {
  if(root != NULL) {
    traverse_tree(root->left);
    printf("word = %s, count = %d\n", root->word, root->count);
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
