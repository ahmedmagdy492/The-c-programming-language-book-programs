#include <stdio.h>
#include <string.h>

void itoa_(int n, char s[]);
void rev(char s[]);

int main() {
  char result[7];
  memset(result, 0, 7);
  int value = -2147483648;//0b11111111111111111111111111111111;

  itoa_(value, result);

  printf("%s\n", result);
}

void itoa_(int _n, char s[]) {
  int i = 0, sign = 0;
  long long n = 0;

  if(_n < 0) {
    sign = 1;
    n = _n;
    n *= -1;
  }

  do {
    s[i++] = (n % 10) + '0';
  }
  while((n /= 10) > 0);

  if(sign)
    s[i++] = '-';

  s[i] = '\0';

  rev(s);
}

void rev(char s[]) {
  int i = 0, j = strlen(s)-1;

  for(; i < j; ++i, --j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}
