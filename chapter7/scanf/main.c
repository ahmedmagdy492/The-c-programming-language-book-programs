#include <stdio.h>
#include <stdarg.h>

void minscanf(char* fmt, ...);

int main(void) {
  float f;
  minscanf("%f", &f);

  printf("%f\n", f);
}

void minscanf(char* fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  char* p = fmt;
  char cval;
  int ival;
  float fval;

  while(*p) {
    if(*p != '%') {
      ++p;
      continue;
    }
    switch(*++p) {
    case 'c': {
      scanf("%c", &cval);
      int* ptr = va_arg(ap, int*);
      *ptr = cval;
    }
    break;
    case 'd': {
      scanf("%d", &ival);
      int* ptr = va_arg(ap, int*);
      *ptr = ival;
    }
    break;
    case 'f': {
      scanf("%f", &fval);
      float* ptr = va_arg(ap, float*);
      *ptr = fval;
    }
    break;
  }
  }
  
  va_end(ap);
}
