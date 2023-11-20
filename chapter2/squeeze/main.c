#include <stdio.h>

void squeeze(char str1[], char str2[]);

int main() {
  char str1[] = "ahmed magdy!";
  char str2[] = "mohamed ahmed";
  squeeze(str1, str2);

  printf("%s\n", str1);
}

void squeeze(char str1[], char str2[]) {
  int i, j, c;
  int wasFound = 0;
  c = 0;
  
  for(i = 0; str1[i] != '\0'; ++i) {
    for(j = 0; str2[j] != '\0'; ++j) {
      if(str1[i] == str2[j]) {
	wasFound = 1;
	break;
      }
      else {
	wasFound = 0;
      }
    }
    if(!wasFound) {
      str1[c++] = str1[i];
    }
  }

  str1[c] = '\0';
}
