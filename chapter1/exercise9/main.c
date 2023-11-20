#include <stdio.h>
#include <string.h>
#define MAX_LINE 1000

void rev_str(char* line, int len);

main() {
  int c, counter;
  char line[MAX_LINE];
  memset(line, 0, MAX_LINE);

  counter = 0;

  while((c = getchar()) != EOF) {
    if(c != '\n' && counter < MAX_LINE) {
      line[counter] = c;
      ++counter;
    }
    else {
      rev_str(line, counter);
      printf("%s\n", line);
      memset(line, 0, MAX_LINE);
    }
  }
}

void rev_str(char* line, int len) {
  int j, i, temp;
  j = 0;

  for(i = len-1; i >= j; --i, ++j) {
    temp = line[i];
    line[i] = line[j];
    line[j] = temp;
  }
}
