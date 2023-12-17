#include <assert.h>
#include <stdio.h>

#include "types.h"
#include "binary_search.h"

// binary search tests
// check whether returns the correct index in case word exists
void correctMidIndex() {
  int actual = bin_search(keywords, 0, NKEY, "if");
  int expected = 6;
  printf("actual = %d, expected = %d\n", actual, expected);
  assert(actual == expected);
}

void correctStartIndex() {
  int actual = bin_search(keywords, 0, NKEY, "case");
  int expected = 1;
  printf("actual = %d, expected = %d\n", actual, expected);
  assert(actual == expected);
}

void correctEndIndex() {
  int actual = bin_search(keywords, 0, NKEY, "unsigned");
  int expected = 9;
  printf("actual = %d, expected = %d\n", actual, expected);
  assert(actual == expected);
}

void wordNotExist() {
  // check whether returns -1 incase non existing word
  int actual = bin_search(keywords, 0, NKEY, "name");
  int expected = -1;
  printf("actual = %d, expected = %d\n", actual, expected);
  assert(actual == expected);
}

void wordIsEmpty() {
  // check whether returns -1 incase passing ""
  int actual = bin_search(keywords, 0, NKEY, "");
  int expected = -1;
  printf("actual = %d, expected = %d\n", actual, expected);
  assert(actual == expected);
}

void wordIsNull() {
  // check if returns -1 when word is null
  int actual = bin_search(keywords, 0, NKEY, '\0');
  int expected = -1;
  printf("actual = %d, expected = %d\n", actual, expected);
  assert(actual == expected);
}

int main(void) {
  correctMidIndex();
  correctStartIndex();
  correctEndIndex();
  wordNotExist();
  wordIsEmpty();
  wordIsNull();
}
