#include <stdio.h>
#include <string.h>

void itoa_(char*, int);
void rev(char*);

int main() {
  int number = 123;
  char s[10];

  itoa_(s, number);
  
  printf("%s\n", s);
}

void itoa_(char* s, int n) {
  char* ptr = s;
  int sign = 0;
  if(n < 0) {
    *s++ = '-';
    n *= -1;
    sign = 1;
  }
  int q = n / 10;
  int r = n % 10;
  *s++ = r + '0';
  
  while(q > 0) {
    r = q % 10;
    q = q / 10;
    *s++ = r + '0';
  }
  *s = '\0';
  if(sign) {
    rev(ptr+1);
  }
  else {
    rev(ptr);
  }
}

void rev(char* s) {
  char *t = s + strlen(s) - 1;
  
  for(;s <= t; ++s, --t) {
    char c = *s;
    *s = *t;
    *t = c;
  }
}
