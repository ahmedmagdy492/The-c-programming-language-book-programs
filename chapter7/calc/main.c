#include <stdio.h>

int main(int argc, char** argv) {
  double value1 = 0, value2 = 0;
  char operator = '-';

  while() {
    int result = scanf("%lf %lf %c", &value1, &value2, &operator);
    if(result == 3) {
      switch(operator) {
        case '-':
        printf("%0.3f\n", value1 - value2);
        break;
        case '+':
        printf("%0.3lf\n", value1 + value2);
        break;
        case '*':
        printf("%0.3lf\n", value1 * value2);
        break;
        case '/':
        if(value2 != 0) {
          printf("%0.3lf\n", value1 / value2);
        }
        else {
          printf("Error: Dividing by zero\n");
          return -1;
        }
        break;
        default:
        printf("Invalid Operator\n");
        break;
      }
    }
  }
}