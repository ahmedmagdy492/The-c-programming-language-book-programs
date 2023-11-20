#include <stdio.h>
#include <string.h>

#define MAX_CHAR_LEN 100
int buffer[MAX_CHAR_LEN];
int bufft = 0;

int getch(void) {
  --bufft;
  return (bufft < 0) ? getchar() : buffer[bufft];
}

void ungetch(int c) {
  if(bufft < MAX_CHAR_LEN) {
    buffer[bufft++] = c;
  }
}

void ungets(char s[]) {
  int i = 0;

  while(s[i] != '\0') {
    ungetch(s[i]);
    ++i;
  }
}

int main(void) {
  char c;
  int i = 0;
  char buffer[MAX_CHAR_LEN];
  memset(buffer, 0, MAX_CHAR_LEN);

  while((c = getch()) != EOF) {
    buffer[i] = c;
    ++i;
  }

  printf("%d\n", c);
}
