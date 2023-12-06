#pragma once
#define MAX_LEN 100

typedef enum Token {
  None,
  FunctionCall,
  ArrayOf,
  ArrayOfSize,
  PointerTo,
  Id,
  TypeChar,
  TypeInt,
  TypeFloat,
  TypeVoid,
  TypeDouble,
  TypeShort,
  TypeLong,
  Const
} Token;

static int top = 0;
static int arr[MAX_LEN];

void Push(Token token) {
  if(top < MAX_LEN) {
    arr[top++] = token;
  }
}

Token Pop() {
  if(top > 0) {
    return arr[--top];
  }

  return None;
}
