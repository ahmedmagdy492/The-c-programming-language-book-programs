#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 1000
#define NO_LINES 100
#undef getline

void sort(char** lines, int lines_count);
int get_line(char* line);

int main(int argc, char** argv) {
  if(argc == 1) {
    char *line1 = (char*)malloc(sizeof(char)*MAX_LINE);
    char* lines[NO_LINES] = { line1 };
    int i = 0;

    while((get_line(lines[i++]) != EOF)) {
      lines[i] = (char*)malloc(sizeof(char)*MAX_LINE);
      if(i == NO_LINES) {
	break;
      }
    }
    
    sort(lines, i);
    int len = i;

    for(i = 0; i < len; ++i) {
      printf("%s\n", lines[i]);
      free(lines[i]);
    }
  }
  else {
    // TBD: accept files
  }
}

int get_line(char* line) {
  int c, i = 0;

  while((c = getchar()) != '\n' && c != EOF) {
    *line++ = c;
    ++i;
    if(i == MAX_LINE)
      return EOF;
  }

  return c;
}

void sort(char** lines, int lines_count) {
  int i, j;

  for(i = 0; i < lines_count; ++i) {
    for(j = i+1; j < lines_count; ++j) {
      if(*lines[i] > *lines[j]) {
	char* temp = lines[i];
	lines[i] = lines[j];
	lines[j] = temp;
      }
    }
  }
}
