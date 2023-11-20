#include <stdio.h>

char* month_name(int n) {
  static char* months[] = {
    "Illegal Month", "Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"
  };
  
  return (n > 12 || n < 1) ? months[0] : months[n];
}

int main(void) {
  printf("%s\n", month_name(4));
}
