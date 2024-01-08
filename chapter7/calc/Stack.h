#include <assert.h>

#define MAX_STACK 100

struct Stack {
  unsigned int top;
  double arr[MAX_STACK];
};

typedef struct Stack Stack;

void push(Stack* this, double value) {
  if(this->top < MAX_STACK) {
    this->arr[this->top++] = value;
  }
}

double pop(Stack* this) {
  assert((this->top-1) >= 0);
  
  return this->arr[--this->top];
}
