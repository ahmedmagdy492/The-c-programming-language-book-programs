#include <stdio.h>

int bin_search(int v[], int len, int x);

int main() {
  int v[] = {1, 2, 3, 4, 5};

  int result = bin_search(v, 5, 5);
  printf("%d\n", result);
}

int bin_search(int v[], int len, int x) {
  int low = 0, end = len-1;

  while(low <= end) {
    int mid = (low + end) / 2;

    if(v[mid] == x) {
      return mid;
    }
    else if(v[mid] > x) {
      end = mid-1;
    }
    else {
      low = mid+1;
    }
  }

  return -1;
}
