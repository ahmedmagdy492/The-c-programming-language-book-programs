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

int extract_next_word(char* input, char* output) {
  int in_word = 0, out_index = 0, in_comment = 0, word_start_index = -1;
  
  while(input[current_index] != '\0') {
    if(!isspace(input[current_index])
       && !in_word) {
      // if first char in word is # or / or "
      if(input[current_index] == '/' && in_comment == 0) {
	in_comment = 1;
      }
      else if(input[current_index] == '/' && in_comment == 1) {
	return EOF;
      }
      else {
	in_word = 1;
	word_start_index = current_index;
      }
      if(isdigit(input[current_index]) || input[current_index] == '#' || input[current_index] == '"') {
        return EOF;
      }
    }
    else if(isspace(input[current_index]) && in_word) {
      in_word = 0;
      output[out_index] = '\0';
      return word_start_index;
    }
    if(in_word) {
      if(isalpha(input[current_index])) {
	output[out_index++] = input[current_index];
      }
    }
    ++current_index;
  }

  if(in_word) {
    // handling the last word
    output[out_index] = '\0';
    return word_start_index;
  }

  return EOF;
}
