#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NCHAR 1000
#define NLINE 100

struct Line {
  int line_no;
  char line[NCHAR];
  char filename[100];
};

typedef struct Line Line;

static Line arr[NLINE];

static int arr_counter = 0;

int main(int argc, char** argv) {
  if(argc == 2) {
    // take input from stdin
    char* pattern = argv[1];
    char* line = (char*)malloc(sizeof(char)*NCHAR);
    size_t len = NCHAR, line_no = 1;

    while(getline(&line, &len, stdin) != EOF) {
      if(strstr(line, pattern) != NULL) {
	arr[arr_counter].line_no = line_no;
	strncpy(arr[arr_counter].line, line, len);
	++arr_counter;
	if(arr_counter == NLINE) {
	  break;
	}
      }
      ++line_no;
    }

    printf("\nFindings:\n");
    
    int i;
    for(i = 0;i < arr_counter; ++i) {
      printf("%d: %s", arr[i].line_no, arr[i].line);
    }

    free(line);
    return 0;
  }
  else if(argc > 2) {
    // read files
    while(--argc > 1) {
      FILE* fd = fopen(argv[argc], "r");
      if(fd == NULL) {
	fprintf(stderr, "Unable to find file %s\n", argv[argc]);
	return 1;
      }

      char* pattern = argv[1];
      char* line = (char*)malloc(sizeof(char)*NCHAR);
      int line_no = 1;

      while(fgets(line, NCHAR, fd) != NULL) {
	if(strstr(line, pattern) != NULL) {
	  arr[arr_counter].line_no = line_no;
	  strncpy(arr[arr_counter].line, line, strlen(line));
	  strncpy(arr[arr_counter].filename, argv[argc], strlen(argv[argc]));
	  ++arr_counter;
	  if(arr_counter == NLINE) {
	    break;
	  }
	}
      }

      fclose(fd);
      free(line);
    }

    printf("Findings:\n");
    
    int i;
    for(i = 0;i < arr_counter; ++i) {
      printf("in file: %s\n", arr[i].filename);
      printf("%d: %s", arr[i].line_no, arr[i].line);
    }
    
    return 0;
  }
  else {
    fprintf(stderr, "Usage: %s <pattern> [files...]\n", argv[0]);
    return 1;
  }
}
