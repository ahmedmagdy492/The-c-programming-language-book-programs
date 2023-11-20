#include <stdio.h>
#include <string.h>
#include <math.h>

double atof_(char s[]);
int atoi_(char s[]);

int main() {
  char s[] = "-50e-2";

  double result = atof_(s);

  printf("%f\n", result);

  /*int result = atoi_(s);
    printf("%d\n", result);*/
}

int atoi_(char s[]) {
  return (int)atof_(s);
}

double atof_(char s[]) {
  int i = 0, sign = 0, has_sci_not = 0, exp = 0;
  double result = 0, divisor = 1;

  if(s[0] == '-') {
    sign = 1;
    i = 1;
  }

  while(s[i] != '\0') {
    if(s[i] == '.') {
      int t;
      for(t = strlen(s)-1; t > i; --t) {
	divisor *= 10;
      }
      ++i;
      continue;
    }
    else if(s[i] == 'e' || s[i] == 'E') {
      has_sci_not = 1;
      break;
    }
    result = (result*10) + (s[i] - '0');
    ++i;
  }

  if(sign)
    result *= -1;

  sign = 0;

  result = (result / divisor);

  if(has_sci_not) {
    ++i;
    while(s[i] != '\0') {
      if(s[i] == '-') {
	sign = 1;
	++i;
	continue;
      }
      exp = (exp*10) + (s[i] - '0');
      ++i;
    }
    if(sign)
      exp *= -1;

    result *= pow(10, exp);
  }

  return result;
}
