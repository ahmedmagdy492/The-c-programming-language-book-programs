#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_SIZE 1000

int read_line(int* line_len, char* line);
void print_line(char* line, int len);
char* trim_begin(char* line, int len, int* new_len);
char* trim_end(char* line, int len, int* new_len);

main() {
  int line_len;
  int shouldClose;

  line_len = 0;
  shouldClose = 0;

  while(shouldClose != EOF) {

    char* current_line = (char*)malloc(sizeof(char)*LINE_SIZE);
    shouldClose = read_line(&line_len, current_line);

    int trimmed_line_len;
    trimmed_line_len = 0;
    char* trimmed_line = trim_begin(current_line, line_len, &trimmed_line_len);
    print_line(trimmed_line, trimmed_line_len);

    if(trimmed_line == current_line)
      free(trimmed_line);
    else {
      free(trimmed_line);
      free(current_line);
    }
  }
}

int read_line(int* line_len, char* line) {
  int counter, c;

  counter = 0;

  while((c = getchar()) != EOF && counter < LINE_SIZE) {
    if(c == '\n')
      return 0;
    
    line[counter] = c;
    ++counter;
    *line_len = counter;
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

char* trim_begin(char* line, int len, int* new_len) {
  int startsWithBlank, i;
  startsWithBlank = 0;

  for(i = 0; i < len; ++i) {
    if(i == 0) {
      if(line[i] != ' ' && line[i] != '\t') {
	break;
      }
      else {
	startsWithBlank = 1;
      }
    }
    else {
      if(line[i] != ' ' && line[i] != '\t') {
	break;
      }
    }
  }

  if(startsWithBlank) {
    int newLen, j;
    newLen = len - i + 1;
    char* arr = (char*)malloc(sizeof(char)*newLen);
    for(j = 0; j < newLen; ++j) {
      arr[j] = line[i];
      ++i;
    }
    *new_len = newLen;
    
    return arr;
  }
  else {
    *new_len = len;
  }
  
  return line;
}

char* trim_end(char* line, int len, int* new_len) {
  int i, endsWithBlanks;
  endsWithBlanks = 0;

  for(i = len-1; i >= 0; --i) {
    if(i == len-1) {
      if(line[i] != ' ' && line[i] != '\t') {
	break;
      }
      else {
	endsWithBlanks = 1;
      }
    }
    else {
      if(line[i] != ' ' && line[i] != '\t') {
	break;
      }
    }
  }

  if(endsWithBlanks) {
    char* arr = (char*)malloc(sizeof(char)*i+1);
    int j;
    j = 0;
    *new_len = i+1;
    for(j = 0; j < i+1; j++) {
      arr[j] = line[j];
    }
    return arr;
  }
  else {
    *new_len = len;
  }
  return line;
}
