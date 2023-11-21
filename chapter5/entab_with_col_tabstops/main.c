#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUFF_LEN 100000
#define TAB_WIDTH 4
#define M 1
#define N 8

int get_line(char* s);
void entab(char* input, int ncols, int startcol);

int main(int argc, char* argv[]) {
  int c, i = 0, m = M, n = N;
  int isNPassed = 0, isMPassed = 0, nArgIndex = -1, mArgIndex = -1;

  if(argc >= 2) {
    // parsing arguments
    int counter;

    for(counter = 1; counter < argc; ++counter) {
      char* pchar = argv[counter];

      while(*pchar != '\0') {
	if(*pchar == '-') {
	  // there are some command line arguments passed starting with -
	  switch(*++pchar) {
	  case 'm':
	    isMPassed = 1;
	    mArgIndex = counter+1;
	    break;
	  default:
	    printf("Invalid argument: -%c\n", *pchar);
	    return 1;
	  }
	}
	else if(*pchar == '+') {
	  // there are some command line arguments passed starting with -
	  switch(*++pchar) {
	  case 'n':
	    isNPassed = 1;
	    nArgIndex = counter+1;
	    break;
	  default:
	    printf("Invalid argument: +%c\n", *pchar);
	    break;
	  }
	}
	++pchar;
      }
    }

    // processing the arguments values
    if(mArgIndex != -1) {
      m = atoi(argv[mArgIndex]);
    }
    if(nArgIndex != -1) {
      n = atoi(argv[nArgIndex]);
    }
  }
  
  char buffer[MAX_BUFF_LEN];
  
  while((c = getchar()) > 0) {
    if(i < (MAX_BUFF_LEN - 1))
      buffer[i++] = c;
  }

  buffer[i] = '\0';

  entab(buffer, n, m);
}

void entab(char* input, int n, int m) {
  char buff[MAX_BUFF_LEN];
  int i = 0, j = 0, nextTabStop = m+n;

  while(input[j] != '\0') {
    if(input[j] == ' ') {
      int counter = 1;
      while(input[j+counter] == ' ') {
        if(j+counter == nextTabStop) {
	  break;
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
