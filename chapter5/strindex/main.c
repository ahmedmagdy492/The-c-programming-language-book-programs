#include <stdio.h>

int strindex(char* s, char* t);

int main() {
  char* str1 = "ahmed";
  char* str2 = "hm";

  printf("%d\n", strindex(str1, str2));
}

int strindex(char* s, char* t) {
  char* start = s;
  
  for(; *s != '\0'; ++s) {
    if(*s == *t) {
      char *sTmp = s, *tTmp = t;
      while((*sTmp++ == *tTmp++) && (*tTmp != '\0' && *sTmp != '\0')) 
	;
      if(*tTmp == '\0')
	return s - start;
    }
  }

  return -1;
}
