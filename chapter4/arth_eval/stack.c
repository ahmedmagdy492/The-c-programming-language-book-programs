#include <stdio.h>
#include "calc.h"

#define MAXLEN 100
static int top = 0;
static double val[MAXLEN];

void push(double value) {
  if(top < MAXLEN)
    val[top++] = value;
}

double pop() {
  if(top > 0)
    return val[--top];
  return 0.0;
}
