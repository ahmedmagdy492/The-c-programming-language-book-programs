#pragma once

#define MAX_CHARS_IN_WORD 1000
#define MAX_INDEX 100


struct WordRef {
  char word[MAX_CHARS_IN_WORD];
  int indexes[MAX_INDEX];
  int cur_index;
};

typedef struct WordRef WordRef;
