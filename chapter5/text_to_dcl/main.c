#include <stdio.h>
#include <string.h>

#include "stack.h"

#define NWORDS 11
#define MAX_ID_LEN 256
#define MAX_TOKEN 100

static const char* words[] = {
  "array of", "array of size", "function returning", "pointer to", "int", "char", "long", "short", "void", "double", "float"
};
char id[MAX_ID_LEN];
int cur = 0;
Token temp[MAX_TOKEN];

void GetTokens(char* input);
Token GetTokenBasedOnName(const char* name);
void PrintStr(char*, int);

int main(int argc, char** argv) {
  if(argc >= 2) {

    GetTokens(argv[1]);

    Token tokenType;

    while((tokenType = Pop()) != None) {
      switch(tokenType) {
      case Id:
	printf("%s", id);
	while(cur >= 0) {
	  if(temp[cur] == FunctionCall)
	    printf("()");
	  else if(temp[cur] == ArrayOf)
	    printf("[]");
	  --cur;
	}
	break;
      case FunctionCall:
	temp[cur++] = FunctionCall;
	break;
      case ArrayOf:
	if(cur > 0) {
	  if(temp[cur-1] == FunctionCall) {
	    temp[cur-1] = ArrayOf;
	    temp[cur++] = FunctionCall;
	  }
	  else {
	    temp[cur++] = ArrayOf;
	  }
	}
	else {
	  temp[cur++] = ArrayOf;
	}
	break;
      case PointerTo:
	printf("*");
	break;
      case TypeChar:
	printf("char ");
	break;
      case TypeInt:
	printf("int ");
	break;
      case TypeFloat:
	printf("float ");
	break;
      case TypeVoid:
	printf("void ");
	break;
      case TypeDouble:
	printf("double ");
	break;
      case TypeShort:
	printf("short ");
	break;
      case TypeLong:
	printf("long ");
	break;
      }
    }

    printf("\n");
  }
}

void GetTokens(char* input) {
  int i, inputLen = strlen(input);
  
  int counter = 0;
  for (; input[counter] != ' '; ++counter)
    ;
  memcpy(id, input, counter++);
  id[counter] = '\0';
  Push(Id);

  for(i = 0; i < NWORDS; ++i) {
    int len = strlen(words[i]);
    int j = 0;

    for(; (j+len-1) < inputLen; ++j) {
      if(strncmp(input+j, words[i], len) == 0 && *(input+j-1) == ' ') {
	Push(GetTokenBasedOnName(words[i]));
      }
    }
  }
}

Token GetTokenBasedOnName(const char* name) {
  if(strcmp(name, "pointer to") == 0) {
    return PointerTo;
  }
  else if(strcmp(name, "array of") == 0) {
    return ArrayOf;
  }
  else if(strcmp(name, "array of size") == 0) {
    return ArrayOfSize;
  }
  else if(strcmp(name, "function returning") == 0) {
    return FunctionCall;
  }
  else if(strcmp(name, "int") == 0) {
    return TypeInt;
  }
  else if(strcmp(name, "short") == 0) {
    return TypeShort;
  }
  else if(strcmp(name, "char") == 0) {
    return TypeChar;
  }
  else if(strcmp(name, "void") == 0) {
    return TypeVoid;
  }
  else if(strcmp(name, "double") == 0) {
    return TypeDouble;
  }
  else if(strcmp(name, "float") == 0) {
    return TypeFloat;
  }
  else if(strcmp(name, "long") == 0) {
    return TypeLong;
  }

  return None;
}

void PrintStr(char* str, int len) {
  int i;

  for(i = 0;i < len; ++i) {
    printf("%c", str[i]);
  }

  printf("\n");
}
