#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF_LEN 200

struct key_value {
  int beginIndex;
  int endIndex;
};

struct key_value* alloc_blanks(char buffer[], int* allocated_len) {
  int i, c, blank_counter;
  int blankBegin;
  struct key_value* indexes = (struct key_value*)malloc(sizeof(struct key_value)*BUFF_LEN);

  blankBegin = -1;
  c = 0;
  blank_counter = 0;

  for(i = 0; i < BUFF_LEN; ++i) {
    if(buffer[i] == ' ') {
      if(blankBegin == -1)
	blankBegin = i;
      ++blank_counter;
    }
    else {
      if(blank_counter > 1) {
	indexes[c].beginIndex = blankBegin;
	indexes[c].endIndex = i;
	++c;
	blank_counter = 0;
      }

      blankBegin = -1;
    }
  }
  
  *allocated_len = c;
  return indexes;
}

char* remove_blanks(char buffer[], int begin, int end) {
  int i, j, count;
  char *copy = (char*)malloc(sizeof(char)*BUFF_LEN);
  count = 0;

  for(i = 0; i < BUFF_LEN; ++i) {
    copy[count] = buffer[i];
    ++count;
    if(i == begin+1) {
      for(j = 0; j < BUFF_LEN-i; ++j) {
	 copy[count] = buffer[end+j];
	 ++count;
      }
      break;
    }
  }

  return copy;
}

int main() {
  int c;
  int count;
  char arr[BUFF_LEN];

  count = 0;

  memset(arr, 0, BUFF_LEN);

  while((c = getchar()) != EOF) {
    arr[count] = c;
    ++count;
    
    if(count == BUFF_LEN || c == '\n') {
      int len;
      len = 0;
      struct key_value* blanks = alloc_blanks(arr, &len);

      int i;
      char *copy;
      for(i = 0; i < len; ++i) {
	copy = remove_blanks(arr, blanks[i].beginIndex, blanks[i].endIndex);

	printf("final: %s\n", copy);

	if(copy)
	  free(copy);
      }
      
      if(blanks)
	free(blanks);

      count = 0;
    }
  }
}
