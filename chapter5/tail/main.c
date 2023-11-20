#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define MAX_BUF_SIZE 10000

int get_line(char* s);
void print_last_n_lines(int n);

int main(int argc, char* argv[]) {
  if(argc == 3) {
    int n = N, nprovided = 0, i = 0;

    for (i = 1; i < argc; ++i) {
      if(*argv[i] == '-') {
	char* ptr = argv[i];
	while(*++ptr != '\0') {
	  switch(*ptr) {
	  case 'n':
	    nprovided = 1;
	    break;
	  default:
	    printf("invalid argument: -%c\n", *ptr);
	    return 1;
	  }
	}
      }
    }

    if(nprovided) {
      // reading the n parameter value
      n = atoi(argv[argc-1]);

      if(n < 0) {
	n = N;
      }

      // print last n lines
      print_last_n_lines(n);
    }
  }
  else {
    // no arguments provided
    print_last_n_lines(N);
  }
}

int get_line(char* s) {
  int c = 0, len = 0;

  while((c = getchar()) != EOF && c != '\n') {
    *s++ = c;
    ++len;
  }

  if(c == EOF)
    return EOF;

  *s = '\n';
  ++len;

  return len;
}

void print_last_n_lines(int n) {
  char buffer[MAX_BUF_SIZE];
  memset(buffer, 0, MAX_BUF_SIZE);
  int offset = 0, len = 0;

  while( (len = get_line(buffer+offset)) > 0) {
    offset += len;
  }

  offset += len;
  int index = 0;
  while(buffer < (buffer+offset)) {
    if(*(buffer+offset-1) == '\n') {
      --n;
    }
    if(n == 0) {
      index = offset;
      break;
    }
    --offset;
  }

  printf("%s", buffer+index);
}
