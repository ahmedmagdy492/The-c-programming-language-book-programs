#include <stdio.h>
#include <stdlib.h>

/*
  A Program that prints all input lines that their length > 80
*/

#define LINE_SIZE 1000

int read_line(int* line_len, char* line);
void print_line(char* line, int len);

main() {
  int line_len;
  int shouldClose;

  line_len = 0;

  shouldClose = 0;

  while(shouldClose != EOF) {

    char* current_line = (char*)malloc(sizeof(char)*LINE_SIZE);
    shouldClose = read_line(&line_len, current_line);
    
    if(line_len > 80)
      print_line(current_line, line_len);

    free(current_line);
  }
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

void print_line(char* line, int len) {
  int i;

  for(i = 0; i < len; ++i) {
    printf("%c", line[i]);
  }

  printf("\n");
}
