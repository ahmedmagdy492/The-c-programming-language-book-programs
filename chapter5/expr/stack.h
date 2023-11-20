
#define MAX_STACK 100

static int stack[MAX_STACK];
static int top = -1;

void push(int v) {
  if(++top < MAX_STACK)
    stack[top] = v;
}

int pop() {
  if(top >= 0)
    return stack[top--];
  return -1879764165;
}
