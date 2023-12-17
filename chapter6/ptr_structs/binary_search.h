#pragma once
#include <string.h>

// array of struct keyword_count, int, int, string -> int
// it takes an array of sorted keyword_count along with its length as well as at which index to start scanning the array and searches for the given string in array of structs if found return index other wise -1

// stub
//  int bin_search(struct keyword_count keys[], int start, int len, char* word) {
// return 0;
// }

// template
/*int bin_search(struct keyword_count keys[], int start, int len, char* word) {
  // get mid index (start + last / 2)
  // cmp_result = strcmp arr[mid], word
  // if cmp_result == 0
  //    return mid
  // else if cmp_result < 0
  //    bin_search second half
  // else
  //    bin_search first half
  // return -1
  return 0;
}*/

struct keyword_count* bin_search(struct keyword_count* keys, struct keyword_count* start, struct keyword_count* len, char* word) {

  if(!word || strcmp(word, "") == 0)
    return NULL;

  if(start > len)
    return NULL;
  
  struct keyword_count* mid = start + (len-start) / 2;
  int cmp_result = strncmp((*mid).word, word, strlen(word));

  if(cmp_result == 0) {
    return mid;
  }
  else if(cmp_result > 0) {
    return bin_search(keys, start, mid, word);
  }
  
  return bin_search(keys, mid+1, len, word);
}
