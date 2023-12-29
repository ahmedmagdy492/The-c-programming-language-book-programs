#pragma once
#include <string.h>
#include <ctype.h>

// NOTE: 1 static variable to keep track of the current position in the input string
// String, String[out] -> String
// given a string return the next word in string (a word is any chars between 2 spaces)

// stub
//void extract_word(char* input) {
//  input = '\0';
//}

static int current_index = 0;

void reset_index() {
  current_index = 0;
}

char* extract_next_word(char* input, char* output) {
  int in_word = 0, out_index = 0, in_comment = 0, in_string = 0;
  
  while(input[current_index] != '\0') {
    if(input[current_index] == '"' && in_string == 0) {
      in_string = 1;
      in_word = 1;
    }
    else if(!isspace(input[current_index]) && !in_word) {
      if(input[current_index] == '/' && in_comment == 0) {
	in_comment = 1;
      }
      else if(input[current_index] == '/' && in_comment == 1) {
	return output;
      }
      else {
	in_word = 1;
      }
    }
    else if(input[current_index] == '"' && in_string) {
      in_string = 0;
    }
    else if(!in_string && isspace(input[current_index]) && in_word) {
      in_word = 0;
      output[out_index] = '\0';
      return output;
    }
    if(in_word) {
      output[out_index++] = input[current_index];
    }
    ++current_index;
  }

  if(in_word) {
    output[out_index] = '\0';
    return output;
  }

  return '\0';
}
