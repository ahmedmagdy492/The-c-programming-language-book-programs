#include <stdio.h>

#define FOREVER for(;;)
#define PI 3.14
#define C_AREA(r) PI*r
#define MAX(A, B) ((A > B) ? A : B)
#define sqr(x) x*x
#define dprint(expr) printf(#expr "%g\n", expr)
// #<formal parameter name> will be replaced by the actual value passed to the the macro as it's (as a string)
#define paste(x,y) x ## y // concatenates the 2 passed arguments

int main() {
  //dprint(12/2);
  
  /*double area = C_AREA(1);
    printf("%f\n", area);*/

  /*int n1 = 12;
  int n2 = 33;

  printf("%d\n", MAX(n1, n2));*/

  //printf("%d\n", sqr(2+1));

  printf("%d\n", paste:(1, 2));
}
