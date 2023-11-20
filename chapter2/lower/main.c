#include <stdio.h>

void lower(char str[]);

int main() {
  char str[] = "AHMeD";
  lower(str);

  printf("%s\n", str);
}

void lower(char str[]) {
  int i;

  while(str[i] != '\0') {
    str[i] = (str[i] >= 65 && str[i] <= 90) ? str[i] + 32 : str[i];
    ++i;
  }
}
