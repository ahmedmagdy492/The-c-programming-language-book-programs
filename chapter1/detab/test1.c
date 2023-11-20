#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_STOP_WIDTH 8

int* get_tab_stops(char* input, int input_len, int tab_stop_width, int* arr_len);
int get_tabstop_based_on_index(int* tabstops, int tabs_len, int index);

main() {
  int len = strlen("\tone\ntwo\tthree\nsixteen\tseventeen\teighteen\n");
  char* str = (char*)malloc(sizeof(char)* len+1);
  memset(str, 0, len+1);
  memcpy(str, "\tone\ntwo\tthree\nsixteen\tseventeen\teighteen\n", len);

  char* newStr = (char*)malloc(sizeof(char)*len+1);
  memset(newStr, 0, len+1);

  int arr_len = 0, i;
  int* arr = get_tab_stops(str, len, TAB_STOP_WIDTH, &arr_len);

  for(i = 0; i < len; ++i) {
    if(str[i] == '\t') {
      int nearest_index = get_tabstop_based_on_index(arr, arr_len, i);
      int j;
      int nOfSpaces;
      nOfSpaces = nearest_index - i;
      for(j = 0; j < nOfSpaces;++j) {
	newStr[i] = ' ';
      }
    }
    else {
      newStr[i] = str[i];
    }
  }

  printf("%s\n", newStr);

  free(arr);
  free(str);
  free(newStr);
}

int* get_tab_stops(char* input, int input_len, int tab_stop_width, int* arr_len) {
  int numberOfTabStops, i, currentTabStop;
  int* tabStopsIndexes;

  currentTabStop = 0;
  numberOfTabStops = input_len / tab_stop_width;
  *arr_len = numberOfTabStops;
  tabStopsIndexes = (int*)malloc(sizeof(int)*numberOfTabStops);

  for(i = 0; i < numberOfTabStops; ++i) {
    currentTabStop += tab_stop_width;
    tabStopsIndexes[i] = currentTabStop;
  }

  return tabStopsIndexes;
}

int get_tabstop_based_on_index(int* tabstops, int tabs_len, int index) {
  int i, found_index = -1;

  for(i = 0; i < tabs_len; ++i) {
    if(index <= tabstops[i]) {
      found_index = tabstops[i];
      break;
    }
  }

  return found_index;
}
