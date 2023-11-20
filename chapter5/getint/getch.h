#pragma once

#include <stdio.h>

#define SIZE 1000

char buff[SIZE];
int buffp = 0;

int getch() {
  if(buffp <= 0) {
    return getchar();
  }
  return buff[buffp--];
}

void ungetch(int c) {
  if(buffp < SIZE) {
    buff[++buffp] = c;
  }
}
