#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO_CHARS 100

struct char_freq
{
  int c;
  int freq;
};

struct char_freq* count_freq(char* chars) {
  struct char_freq* all = (struct char_freq*)malloc(sizeof(struct char_freq)*NO_CHARS);
  int count, i, j, chars_count;
  count = 0;

  for(i = 0; i < NO_CHARS; ++i) {
    chars_count = 0;
    for(j = i; j < NO_CHARS; ++j) {
      if(chars[i] == chars[j]) {
	++chars_count;
      }
    }

    for(j = 0; j < NO_CHARS; ++j) {
      if(chars[i] == all[j].c) {
	all[j].c = chars[i];
	all[j].freq = chars_count;
      }
    }
  }

  return all;
}

void show_histogram(struct char_freq* all) {
  int i, j;

  for(i = 0; i < NO_CHARS; ++i) {
    printf("%c\t", all[i].c);
    for(j = 0; j < all[i].freq; ++j) {
      printf("|");
    }
    printf("\n");
  }
}

main() {
  int c, count;
  char buffer[NO_CHARS];

  memset(buffer, 0, NO_CHARS);

  count = 0;

  while((c = getchar()) != EOF) {
    if(count < NO_CHARS) {
      buffer[count] = c;
      ++count;
    }
    else {
      struct char_freq* all = count_freq(buffer);
      show_histogram(all);
      count = 0;
      memset(buffer, 0, NO_CHARS);
      free(all);
    }
  }
}
