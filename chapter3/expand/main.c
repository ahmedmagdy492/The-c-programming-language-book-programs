#include <stdio.h>
#include <string.h>

int is_digit(char c);
int is_char(char c);
void expand(char s1[], char s2[]);

int main() {
  char s[] = "-ahmed-a-b-ca-zA-Z0-9-";
  char c[1000];
  memset(c, 0, 1000);

  expand(s, c);

  printf("%s\n", c);
}

void expand(char s1[], char s2[]) {
  int i = 0, j = 0, counter = 0;

  while(s1[i] != '\0') {
    if(i+2 < strlen(s1)) {
      if(is_char(s1[i]) && s1[i+1] == '-' && is_char(s1[i+2])) {
	if(s1[i] < s1[i+2]) {
	  for(j = s1[i]; j <= s1[i+2]; ++j) {
	    s2[counter] = j;
	    ++counter;
	  }
	  i += 2;
	}
	else {
	  s2[counter] = s1[i];
	  ++counter;
	}
      }
      else if(is_digit(s1[i]) && s1[i+1] == '-' && is_digit(s1[i])) {
	if(s1[i] < s1[i+2]) {
	  for(j = s1[i]; j <= s1[i+2]; ++j) {
	    s2[counter] = j;
	    ++counter;
	  }
	  i += 2;
	}
	else {
	  s2[counter] = s1[i];
	  ++counter;
	}
      }
      else {
	s2[counter] = s1[i];
	++counter;
      }
    }
    ++i;
  }
}

int is_char(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int is_digit(char c) {
  return c >= '0' && c <= '9';
}
