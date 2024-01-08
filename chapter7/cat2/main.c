#include <stdio.h>
#include <string.h>
#define NLINE 100

int main(int argc, char** argv) {
  if(argc >= 2) {
    char buffer[NLINE];
    
    while(--argc > 0) {
      FILE* fd = fopen(argv[argc], "r");
      if(fd != NULL) {
	memset(buffer, 0, NLINE);
	while(fgets(buffer, NLINE, fd) != NULL) {
	  printf("%s", buffer);
	}
	putchar('\n');
      }
      else {
	fprintf(stderr, "Cannot Open File: %s\n", argv[argc]);
      }
    }
    return 0;
  }
  else {
    printf("Usage: %s <file...>\n", argv[0]);
    return 1;
  }
}
