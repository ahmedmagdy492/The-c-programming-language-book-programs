#include <stdio.h>
#include <string.h>

void print_pattern(char s[], char p[]);
int contains(char s[], int start, int stop_point, char p[]);

int main(int argc, char* argv[]) {
  char s[] = "my name is ahmed and i am looking forward to print out\n what you think man\n what do you want to do man ?";
  char p[] = "want to do man";
  print_pattern(s, p);
}

void print_pattern(char s[], char p[]) {
  int c, i = 0, start = 0;

  while((c = s[i]) != '\0') {
    if(c == '\n' || s[i+1] == '\0') {
      if(contains(s, start, i, p)){
	int l = start;
	for(; l <= i; ++l) {
	  printf("%c", s[l]);
	}
	printf("\n");
      }
      start = i;
    }
    ++i;
  }
}

int contains(char s[], int start, int stop_point, char p[]) {
  int i, j, c;
  int p_len = strlen(p);

  for(i = start; i < stop_point; ++i) {
    c = i;
    j = 0;
    while(j < p_len && s[c] == p[j]) {
      //printf("s[%d] = %c, p[%d] = %c\n", c, s[c], j, p[j]);
      ++c;
      ++j;
    }

    if(j == p_len) {
      return 1;
    }
  }

  return 0;
}
