#include <stdio.h>

int startsWith2Chars(char s[], char c1, char c2);
int htoi(char s[]);

int main(int argc, char** argv) {
  if(argc == 2) {
    int result = htoi(argv[1]);

    printf("result = %d\n", result);

    return 0;
  }

  printf("Usage: htoi <hex-number>\n");
  return 1;
}

int startsWith2Chars(char s[], char c1, char c2) {

  if(s[0] == c1 && s[1] == c2) {
    return 1;
  }

  return 0;
}

int htoi(char s[]) {
  int i, n;

  if(startsWith2Chars(s, '0', 'x') || startsWith2Chars(s, '0', 'X')) {
    i = 2;
  }

  n = 0;
  for(; s[i] != '\0'; ++i) {
    if(s[i] >= '0' && s[i] <= '9') {
      n = n * 16 + (s[i] - '0');
    }
    else if(s[i] >= 'a' && s[i] <= 'f') {
      n = n * 16 + (10 + s[i] - 'a');
    }
    else if(s[i] >= 'A' && s[i] <= 'F') {
      n = n * 16 + (10 + s[i] - 'A');
    }
  }

  return n;
}
