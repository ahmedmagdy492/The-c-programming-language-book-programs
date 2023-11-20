#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

int main() {
  int type;
  double op2;
  char s[MAXOP];

  while((type = getop(s)) != '\0') {
    switch(type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if(op2 == 0)
	printf("division by zero\n");
      else
	push(pop() - op2);
      break;
    case '\n':
      printf("%.2g\n", pop());
      break;
    default:
      printf("unknown operation %s\n", s);
      break;
    }
  }

  return 0;
}

#define MAXLEN 100
int top = 0;
double val[MAXLEN];

void push(double value) {
  if(top < MAXLEN)
    val[top++] = value;
}

double pop() {
  if(top > 0)
    return val[--top];
  return 0.0;
}

int getch(void);

int getop(char s[]) {
  int i, c;

  while((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  
  if(!isdigit(c) && c != '.')
    return c;
  i = 0;
  if(isdigit(c))
    while(isdigit(s[++i] = c = getch()))
      ;
  if(c == '.')
    while(isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  return NUMBER;
}

#define BUFSIZE 100

char *buf = NULL;
int bufp = 0;
size_t line_size = 0;

int getch(void) {
  if(bufp == 0) {
    if(buf != NULL) {
      free(buf);
    }
    buf = (char*)malloc(sizeof(char)*BUFSIZE);
    getline(&buf, &line_size, stdin);
  }
  if(bufp == BUFSIZE) bufp = 0;
  return buf[bufp++];
}
