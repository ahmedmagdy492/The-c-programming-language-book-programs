#include <stdio.h>
#include <stdarg.h>

void minprintf(char* fmt, ...);

int main(void) {
  minprintf("name: %s, age: %d, char: %c, hex: %X, octal: %o, e: %e, g: %g\n", "ahmed", 29, 'A', 100, 9, 12.232323, 323.4566);
}

void minprintf(char* fmt, ...) {
  char *p, *sval;
  int ival;
  double dval;
  va_list ap;
  char cval;
  va_start(ap, fmt);

  for(p = fmt; *p; p++) {
    if(*p != '%') {
      putchar(*p);
      continue;
    }
    switch(*++p) {
    case 'g':
      dval = va_arg(ap, double);
      printf("%g", dval);
      break;
    case 'e':
      dval = va_arg(ap, double);
      printf("%e", dval);
      break;
    case 'o':
      ival = va_arg(ap, int);
      printf("%o", ival);
      break;
    case 'x':
      ival = va_arg(ap, int);
      printf("%x", ival);
      break;
    case 'X':
      ival = va_arg(ap, int);
      printf("%X", ival);
      break;
    case 'c':
      cval = va_arg(ap, int);
      printf("%c", cval);
      break;
    case 'd':
      ival = va_arg(ap, int);
      printf("%d", ival);
      break;
    case 'f':
      dval = va_arg(ap, double);
      printf("%f", dval);
      break;
    case 's':
      for(sval = va_arg(ap, char*);*sval;sval++) {
	putchar(*sval);
      }
      break;
    default:
      putchar(*p);
      break;
    }
  }

  va_end(ap);
}
