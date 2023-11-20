/*
  Detab Program in ansi c89/c90

  Author: Ahmed Magdy
  Date: 24/08/2023 12:44 am
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_WIDTH 4
#define TAB_STOP_LEN 8

char* detab(char* line, int len, int* new_len);
char* shift_to_right(char* line, int line_len, int noOfSpaces, int start);
void print_line(char* line, int len);

main() {
  //char* str = "\tabcfssa\t\tmona\tahmed\tafsdasfd";
  char* str = "\tone\ntwo\tthree\nsixteen\tseventeen\teighteen\n";
  int new_len;
  new_len = 0;
  char* line = detab(str, strlen(str), &new_len);

  print_line(line, new_len);
  free(line);
}

char* shift_to_right(char* line, int line_len, int noOfSpaces, int start) {
  int newBufferSize, i, j, c;
  char* newBuffer;
  c = 0;

  newBufferSize = line_len + noOfSpaces - 1;
  newBuffer = (char*)malloc(sizeof(char)*newBufferSize);

  for (i = 0; i < newBufferSize;) {
    if(i == start) {
      for(j = 0; j < noOfSpaces; ++j) {
	newBuffer[i] = ' ';
	++i;
      };
    }
    else {
      newBuffer[i] = line[c];
      ++i;
    }
    ++c;
  }

  return newBuffer;
}

void print_line(char* line, int len) {
  int i;

  for(i = 0; i < len; ++i) {
    printf("%c", line[i]);
  }

  printf("\n");
}

char* detab(char* line, int len, int* new_len) {
  int i;
  int nextTabStop, noOfSpaces, lastNewLinePos;

  nextTabStop = 0;
  lastNewLinePos = 0;

  for(i = 0; i < len; ++i) {
    if(line[i] == '\t') {
      nextTabStop += TAB_STOP_LEN;
      if(i < nextTabStop)
	noOfSpaces = nextTabStop - i;
      else
	noOfSpaces = nextTabStop - (i - lastNewLinePos) + 1;

      line = shift_to_right(line, len, noOfSpaces, i);
      len = len + noOfSpaces - 1;
      //i = 0;
    }
    else if (line[i] == '\n') {
      nextTabStop = 0;
    }
  }

  *new_len = len;

  return line;
}
