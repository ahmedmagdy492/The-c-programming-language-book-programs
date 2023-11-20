#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUFF_LEN 100000
#define TAB_WIDTH 4
#define MAX_TAB_STOPS 150

int get_line(char* s);
void entab(char* input, int tabstops[], int ntabstops);

int main(int argc, char* argv[]) {
  int c, i = 0, isTabStopsProvided = 0;
  int tabStops[MAX_TAB_STOPS], ntabstops = 0;

  if(argc == 3) {
    // parsing arguments
    int counter;

    for(counter = 1; counter < argc; ++counter) {
      char* pchar = argv[counter];

      while(*pchar != '\0' && !isTabStopsProvided) {
	if(*pchar == '-') {
	  // there are some command line arguments passed
	  switch(*++pchar) {
	  case 'l':
	    isTabStopsProvided = 1;
	    break;
	  default:
	    printf("Invalid argument: -%c\n", *pchar);
	    return 1;
	  }
	}
	++pchar;
      }

      if(isTabStopsProvided) {
	++counter;
	break;
      }
    }

    // processing the arguments values
    char* strptr = strtok(argv[counter], ",");

    while(strptr != NULL) {
      tabStops[ntabstops++] = atoi(strptr);
      strptr = strtok(NULL, ",");
    }
  }
  
  char buffer[MAX_BUFF_LEN];
  
  while((c = getchar()) > 0) {
    if(i < (MAX_BUFF_LEN - 1))
      buffer[i++] = c;
  }

  buffer[i] = '\0';

  if(isTabStopsProvided) {
    entab(buffer, tabStops, ntabstops);
  }
}

void entab(char* input, int tabstops[], int ntabstops) {
  char buff[MAX_BUFF_LEN];
  int i = 0, j = 0;

  while(input[j] != '\0') {
    if(input[j] == ' ') {
      int counter = 1, isTabStop = 0;
      while(input[j+counter] == ' ' && !isTabStop) {
	int tcounter;
	for(tcounter = 0; tcounter < ntabstops; ++tcounter) {
	  if((j+counter) == tabstops[tcounter]) {
	    isTabStop = 1;
	    break;
	  }
	}
	++counter;
      }
      if(counter == TAB_WIDTH) {
	buff[i++] = '|';
	j += counter-1;
      }
      else {
	buff[i++] = input[j];
      }
    }
    else {
      buff[i++] = input[j];
    }
    ++j;
  }
  buff[i] = '\0';

  printf("%s", buff);
}

int get_line(char* s) {
  int c = 0, len = 0;

  while((c = getchar()) != EOF && c != '\n') {
    *s++ = c;
    ++len;
  }

  if(c == EOF)
    return EOF;

  *s++ = '\n';
  *s = '\0';
  len += 2;

  return len;
}
