#include <stdio.h>
#include "date_conversion.h"

int main() {
  int d = 0, m = 0;
  
  convert_doy_to_dom(60, 1989, &m, &d);

  printf("d=%d, m=%d\n", d, m);
  
  convert_dom_to_doy(1, 3, 1988, &d);

  printf("d=%d\n", d);
}
