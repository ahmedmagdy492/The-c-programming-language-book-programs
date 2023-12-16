#include "extract_word.h"
#include <stdio.h>
#include <assert.h>

#define NCHARS 1000

void emptyString() {
  char actual[NCHARS];
  extract_next_word("", actual);
  char* expected = "";
  printf("actual = %s, expected = %s\n", actual, expected);
  assert(strcmp(actual, expected) == 0);
}

void singleWord() {
  char actual[NCHARS];
  extract_next_word("case", actual);
  char* expected = "case";
  printf("actual = %s, expected = %s\n", actual, expected);
  assert(strcmp(actual, expected) == 0);
}

void manyWords() {
  char actual1[NCHARS];
  extract_next_word("case if", actual1);
  char* expected1 = "case";

  printf("many words test\n");
  printf("actual1 = %s, expected1 = %s\n", actual1, expected1);
  
  assert(strcmp(actual1, expected1) == 0);

  char actual2[NCHARS];
  extract_next_word("case if", actual2);
  char* expected2 = "if";

  printf("actual2 = %s, expected2 = %s\n", actual2, expected2);
  
  assert(strcmp(actual2, expected2) == 0);
}

void wordStartsWithUnderScore() {
  char actual1[NCHARS];
  extract_next_word("case _if", actual1);
  char* expected1 = "case";

  printf("underscore words test\n");
  printf("actual1 = %s, expected1 = %s\n", actual1, expected1);
  
  assert(strcmp(actual1, expected1) == 0);

  char actual2[NCHARS];
  extract_next_word("case if_123 123", actual2);
  char* expected2 = "if_123";

  printf("actual2 = %s, expected2 = %s\n", actual2, expected2);
  
  assert(strcmp(actual2, expected2) == 0);
}

void wordStartsWithNumbers() {
  char actual[NCHARS];
  extract_next_word("123", actual);
  char* expected = "";

  printf("actual = %s, expected = %s\n", actual, expected);

  assert(strcmp(actual, expected) == 0);
}

void wordThatHasNumbers() {
  char actual[NCHARS];
  extract_next_word("a123", actual);
  char* expected = "a123";

  printf("actual = %s, expected = %s\n", actual, expected);

  assert(strcmp(actual, expected) == 0);
}

void wordStartsWithPreprocesser() {
  char actual[NCHARS];
  extract_next_word("#ahmed", actual);
  char* expected = "";

  printf("actual = %s, expected = %s\n", actual, expected);

  assert(strcmp(actual, expected) == 0);
}

void wordStartsWithString() {
  char actual[NCHARS];
  extract_next_word("\"ahmed", actual);
  char* expected = "";

  printf("actual = %s, expected = %s\n", actual, expected);

  assert(strcmp(actual, expected) == 0);
}

int main(void) {
  // you should run every test alone
  //emptyString();
  //singleWord();
  //manyWords();
  //wordStartsWithUnderScore();
  //wordStartsWithNumbers();
  //wordThatHasNumbers();
  //wordStartsWithPreprocesser();
  wordStartsWithString();
}
