#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#include "stack.h"

int eval(int num1, int num2, char op);
int isoperator(char *s);
int atoi_(char* s);
int is_digit(char* s);

int main(int argc, char* argv[]) {
  int i, number, result;

  for(i = 1; i < argc; ++i) {
    if(isoperator(argv[i])) {
      // operator
      int num2 = pop();
      int num1 = pop();
      push(eval(num1, num2, argv[i][0]));
    }
    else if(is_digit(argv[i])) {
      number = atoi_(argv[i]);
      push(number);
    }
  }

  if( (result = pop()) != -1) {
    printf("%d\n", result);
  }
}

int eval(int num1, int num2, char op) {
  int result = 0;

  switch(op) {
  case '-':
    return num1 - num2;
  case '+':
    return num1 + num2;
  case '*':
    return num1 * num2;
  case '/':
    if(num2 != 0)
      return num1 / num2;
    break;
  }
  
  return result;
}

int isoperator(char *s) {
  if(*s == '+' || *s == '/' || *s == '*')
    return 1;
  
  int counter = 0;

  while(*s != '\0') {
    ++counter;
    ++s;
  }

  if(counter == 1 && *s == '-')
    return 1;
  
  return 0;
}

int atoi_(char* s) {
  int result = 0, sign = 0;

  if(*s == '-') {
    sign = 1;
    ++s;
  }
  
  while(*s != '\0') {
    result = result * 10 + (*s - '0');
    s++;
  }

  if(sign)
    result *= -1;

  return result;
}

int is_digit(char* s) {
  if(*s == '-')
    ++s;
  
  while(*s != '\0') {
    if(!isdigit(*s))
      return 0;
    ++s;
  }

  return 1;
}
