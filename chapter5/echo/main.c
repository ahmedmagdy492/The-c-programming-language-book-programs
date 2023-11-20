#include <stdio.h>

int main(int argc, char* argv[]) {
  if(argc > 1) {
    int i;

    for(i = 1; i < argc; ++i) {
      if((i+1) == argc)
	printf("%s\n", argv[i]);
      else
	printf("%s ", argv[i]);
    }
  }
}
