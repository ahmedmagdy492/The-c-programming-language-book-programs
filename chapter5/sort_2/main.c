#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1000
#define NO_LINES 100
#undef getline

enum SortFlags {
  Fold = 1,
  Rev
};

void sort(char** lines, int lines_count, int (*comp)(void*, void*), enum SortFlags);
int get_line(char* line);
void swap(void** p1, void**p2);
void strlower(char* s);

int numcmp(char*, char*);
int dircmp(char*, char*);

int main(int argc, char** argv) {
  if(argc >= 1) {
    char *line1 = (char*)malloc(sizeof(char)*MAX_LINE);
    char* lines[NO_LINES] = { line1 };
    int i = 0, numeric = 0, dir = 0;
    enum SortFlags sortFlags = 0;

    if(argc > 1) {
      int counter;
      for(counter = 1; counter < argc; ++counter) {
        if(*argv[counter] == '-') {
	  char* pchar = argv[counter];
	  
	  while(*++pchar != '\0') {
	     switch(*pchar) {
	     case 'n':
	       numeric = 1;
	       break;
	     case 'r':
	       sortFlags |= Rev;
	       break;
	     case 'f':
	       sortFlags |= Fold;
	       break;
	     case 'd':
	       dir = 1;
	       break;
	     default:
	       printf("invalid argument -%c\n", *pchar);
	       return 1;
	     }
	  }
	}
      }
    }

    while((get_line(lines[i++]) != EOF)) {
      lines[i] = (char*)malloc(sizeof(char)*MAX_LINE);
      if(i == NO_LINES) {
	break;
      }
    }

    if(numeric) {
      sort(lines, i, (int (*)(void*, void*))numcmp, sortFlags);
    }
    else if(dir) {
      sort(lines, i, (int (*)(void*, void*))dircmp, sortFlags);
    }
    else {
      sort(lines, i, (int (*)(void*, void*))strcmp, sortFlags);
    }
   
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

void sort(char** lines, int lines_count, int (*cmp)(void*, void*), enum SortFlags flags) {
  int i, j;
  
  for(i = 0; i < lines_count; ++i) {
    for(j = i+1; j < lines_count; ++j) {
      if((flags & Rev) && (flags & Fold)) {
	strlower(lines[i]);
	strlower(lines[j]);
	if(cmp(lines[i], lines[j]) < 0) {
	   swap((void**)&lines[i], (void**)&lines[j]);
	}
      }
      else if(flags & Rev) {
	if(cmp(lines[i], lines[j]) < 0) {
	   swap((void**)&lines[i], (void**)&lines[j]);
	}
      }
      else if(flags & Fold) {
	strlower(lines[i]);
	strlower(lines[j]);
	if(cmp(lines[i], lines[j]) > 0) {
	  swap((void**)&lines[i], (void**)&lines[j]);
	}
      }
      else {
	if(cmp(lines[i], lines[j]) > 0) {
	  swap((void**)&lines[i], (void**)&lines[j]);
	}
      }
    }
  }
}

int numcmp(char* s1, char* s2) {
  double n1 = atof(s1);
  double n2 = atof(s2);

  if(n1 > n2) {
    return 1;
  }
  else if (n1 < n2){
    return -1;
  }

  return 0;
}

int dircmp(char* s1, char* s2) {
  while(*s1 != '\0' && *s2 != '\0') {
    if( (isalnum(*s1) && isalnum(*s2)) || (isspace(*s1) && isspace(*s2)) ) {
      if(*s1 < *s2) {
	return -1;
      }
      else if(*s1 > *s2) {
	return 1;
      }
    }
    ++s1;
    ++s2;
  }

  return 0;
}

void swap(void** p1, void**p2) {
  void* temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

void strlower(char* s) {
  while(*s != '\0') {
    *s = tolower(*s);
    ++s;
  }
}
