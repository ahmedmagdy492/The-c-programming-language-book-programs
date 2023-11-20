#include <stdio.h>

void shell_sort(int a[], int len);

int main() {
  int a[] = {3, 2, 8, 5, 7, 6, 10, 9, 1};

  shell_sort(a, 9);

  int i = 0;

  for(; i < 9; ++i) {
    printf("%d ", a[i]);
  }

  printf("\n");
}

void shell_sort(int a[], int len) {
  int gap = len, i = 0;

  while(gap > 1) {
    gap = gap / 2;

    for(i = 0; i < len; ++i) {
      if((gap+i) < len) {
	if(a[i] > a[gap+i]) {
	  int temp = a[i];
	  a[i] = a[gap+i];
	  a[gap+i] = temp;
	}
      }
    }
  }
}
