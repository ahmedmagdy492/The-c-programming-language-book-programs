#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_SIZE 10

int read_line(int* line_len, char* line);
char* max_line(char* arr1, int len1, char* arr2, int len2);
void print_line(char* line, int len);

main() {
  int line_len, max_line_len;
  char* current_max = NULL;
  int shouldClose;

  line_len = 0;
  max_line_len = 0;
  shouldClose = 0;

  while(shouldClose != EOF) {

    char* current_line = (char*)malloc(sizeof(char)*LINE_SIZE);
    shouldClose = read_line(&line_len, current_line);

    current_max = max_line(current_max, max_line_len, current_line, line_len);
    max_line_len = max_line_len > line_len ? max_line_len : line_len;
  }

  print_line(current_max, max_line_len);
}

int read_line(int* line_len, char* line) {
  int counter, c;

  counter = 0;

  while((c = getchar()) != EOF && counter < LINE_SIZE) {
    if(c == '\n')
      return 0;
    
    line[counter] = c;
    *line_len = counter;
    ++counter;
  }
  
  return c;
}

char* max_line(char* arr1, int len1, char* arr2, int len2) {
  if(len1 > len2) {
    free(arr2);
    return arr1;
  }
  else {
    free(arr1);
    return arr2;
  }
}

void print_line(char* line, int len) {
  int i;

  for(i = 0; i < len; ++i) {
    printf("%c", line[i]);
  }

  printf("\n");
}
