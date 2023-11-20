#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_SIZE 1024

int endsWith(const char* str, int len, char c);
char* SubString(char* str, int len, int start_index, int howManyCharsToSubstr);

int main(int argc, char** argv) {

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <filename.c>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE* file_handle = NULL;
	file_handle = fopen(argv[1], "r+");

	if (NULL == file_handle) {
		fprintf(stderr, "Error occured while trying to open file: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	size_t size = 0;
	size_t temp = 0;
	char buffer[FILE_SIZE];
	memset(buffer, 0, FILE_SIZE);

	while ((temp = fread(buffer, 1, FILE_SIZE, file_handle)) != 0) {
		size += temp;
	}

	int i, in_comment, output_counter, in_string, in_multi_line_comment;
	char* output = (char*)malloc(sizeof(char)*size);
	memset(output, 0, size);
	
	in_comment = 0;
	output_counter = 0;
	in_string = 0;
	in_multi_line_comment = 0;

	for (i = 0; i < size; ++i) {
	  if(buffer[i] == '"' && in_string == 0) {
	    in_string = 1;
	  }
	  else if(buffer[i] == '"' && in_string == 1) {
	    in_string = 0;
	  }
	  /**/
	  if(i < size-1) {
	    if(in_string == 0 && buffer[i] == '/' && buffer[i+1] == '*') {
	      in_multi_line_comment = 1;
	    }
	    else if(in_multi_line_comment == 1 && buffer[i-1] == '/' && buffer[i-2] == '*') {
	      in_multi_line_comment = 0;
	    }

	    if(in_string == 0 && in_comment == 0 && buffer[i] == '/' && buffer[i+1] == '/') {
	      in_comment = 1;
	    }
	    else if(buffer[i] == '\n' && in_comment == 1){
	      in_comment = 0;
	    }
	  }
	   
	   if(in_comment == 0 && in_multi_line_comment == 0) {
	     output[output_counter] = buffer[i];
	     ++output_counter;
	   }
	}

	fclose(file_handle);

	fprintf(stdout, "%s\n", output);

	free(output);
}

int endsWith(const char* str, int len, char c) {
	return str[len - 1] == c;
}

char* SubString(char* str, int len, int start_index, int howManyCharsToSubstr) {
    char* newStr = (char*)malloc(sizeof(char) * (howManyCharsToSubstr + 1));
    int i, counter;

    for (i = 0; i < len; ++i) {
        if (i == start_index) {
            int j = i;
            for (counter = 0; counter < howManyCharsToSubstr; ++counter) {
                newStr[counter] = str[j];
                ++j;
            }
        }
    }

    newStr[counter] = '\0';

    return newStr;
}
