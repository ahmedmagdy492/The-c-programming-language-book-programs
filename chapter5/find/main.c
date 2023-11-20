#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define NO_LINES 100

int get_line(char* s);

static inline void print_help() {
  printf("-x: prints lines that does not contain <pattern>\n");
  printf("-n: prints line numbers\n");
  printf("-h: prints help\n");
}

int main(int argc, char* argv[]) {
  int found = 0;
  
  if(argc >= 2) {
    int invert = 0, numbers = 0, lineno = 0, i = 0;
    char* pattern = argv[argc-1];
    char line[MAXLINE];

    for(i = 1; i < argc-1; ++i) {
      if(argv[i][0] == '-') {
	char* ptr = argv[i];
	while(*(++ptr) != '\0') {
	  switch(*ptr) {
	  case 'x':
	    invert = 1;
	    break;
	  case 'n':
	    numbers = 1;
	    break;
	    /*case 'h':
	    print_help();
	    break;*/
	  default:
	    found = -1;
	    printf("invalid option: -%c\n", *ptr);
	    return found;
	  }
	}
     }
    }
    
    while(get_line(line) > 0) {
      ++lineno;
      if(invert) {
	if(strstr(line, pattern) == NULL) {
	  if(numbers)
	    printf("%d: ", lineno);
	  printf("%s\n", line);
	}
      }
      else {
	if(strstr(line, pattern) != NULL) {
	  if(numbers)
	    printf("%d: ", lineno);
	  printf("%s\n", line);
	  ++found;
	}
      }
    }
  }
  else {
    printf("Usage: %s pattern\n", argv[0]);
  }

  return found;
}

int get_line(char* s) {
  int c = 0;

  while((c = getchar()) != EOF && c != '\n') {
    *s++ = c;
  }

  if(c == EOF)
    return EOF;

  *s = '\0';

  return c;
}
