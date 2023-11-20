#include <stdio.h>
#include <string.h>

void trim(char s[]);

int main() {
  //char name[] = "ahmed \t\n";
  char name[] = "    ";

  printf("Name Before: %s, len : %d\n", name, strlen(name));

  trim(name);

  printf("Name After: %s, len: %d\n", name, strlen(name));
}

void trim(char s[]) {
  int i = strlen(s)-1;

  while(i >= 0) {

    if(s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
      s[i] = '\0';
    else
      break;

    --i;
  }
}
