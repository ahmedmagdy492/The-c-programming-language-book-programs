#include <stdio.h>
#include <string.h>

#include <sys/param.h>

#define MAX_LINE 1000

int main(int argc, char** argv) {
  if(argc != 3) {
    fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
    return 1;
  }

  // read 2 files
  FILE *file1 = fopen(argv[1], "r"), *file2 = fopen(argv[2], "r");
  if(file1 == NULL) {
    fprintf(stderr, "Unable to read file %s\n", argv[1]);
    return 1;
  }

  if(file2 == NULL) {
    fprintf(stderr, "Unable to read file %s\n", argv[2]);
    fclose(file1);
    return;
  }

  char line1[MAX_LINE], line2[MAX_LINE];

  while(fgets(line1, MAX_LINE, file1) != NULL && fgets(line2, MAX_LINE, file2) != NULL) {
    int min_len = MIN(strlen(line1), strlen(line2));
    if(strncmp(line1, line2, min_len) != 0) {
      printf("dif****** file1:\n");
      printf("%s", line1);
      printf("dif****** file2:\n");
      printf("%s", line2);
      break;
    }
    memset(line1, 0, MAX_LINE);
    memset(line2, 0, MAX_LINE);
  }

  fclose(file1);
  fclose(file2);

  return 0;
}
