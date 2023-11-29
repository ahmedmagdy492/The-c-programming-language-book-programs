#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "TokensStack.h"

// for now we don't support type prefixes such as unsigned and signed
#define KEYWORDS_COUNT 6
#define MAX_TOKEN_LEN 255


static const char* keywords[] = {
  "int", "char", "float", "double", "short", "void"
};
static const char* expr = "char(*(*x())[])();";
static Tokens token_type = None;

char* NextToken(char* output);
void PrintBasedOnName(Tokens token);
Tokens GetTokenTypeByName(char*);
int ExtractSize(char* token);

int main() {
	char token[MAX_TOKEN_LEN];
	memset(token, 0, MAX_TOKEN_LEN);

	while (NextToken(token) != NULL) {
		switch (token_type)
		{
		case CloseParenthis: {
			Tokens current_token = Pop();
			while (current_token != None) {
			  PrintBasedOnName(current_token);
			  current_token = Pop();
			  if (current_token == OpenParenthis) {
			    break;
			  }
			}
		}
			break;
		case ArrayBrackets:
		  int result = 0;
		  if((result = ExtractSize(token)) == 0)
		    printf("array of ");
		  else
		    printf("array of size %d of type ", result);
			break;
		case FunctionCall:
		  printf("function returns ");
			break;
		case Name:
			printf("%s is ", token);
			break;
		case Number:
			break;
		case TypeInt:
		case TypeChar:
		case TypeShort:
		case TypeDouble:
		case TypeFloat:
		case TypeVoid:
		case PointerTo:
		case OpenParenthis:
			Push(token_type);
			break;
		case EndOfLine: {
			Tokens current_token = Pop();
			while (current_token != None) {
				PrintBasedOnName(current_token);
				current_token = Pop();
				if (current_token == OpenParenthis) {
					break;
				}
			}
			printf("\n");
		}
			break;
		}
	}
}

char* NextToken(char* output) {
	static int i = 0;
	int in_string = 0, str_start_index = 0;
	int in_arr_syntax = 0, arr_syntax_start_index = 0;

	for (; expr[i] != '\0'; ++i) {
		if (!isalnum(expr[i])) {
			if (in_string) {
				// checking if the word is a keyword
				int j = 0, end_index = i-1;
				for (j = 0; j < KEYWORDS_COUNT; ++j) {
					
					if (strncmp(keywords[j], expr + str_start_index, end_index) == 0) {
						in_string = 0;
						memcpy(
							output, 
							expr + str_start_index,
							end_index - str_start_index+1
						);
						token_type = GetTokenTypeByName(output);
						return output;
					}
				}

				if (in_string) {
					// if it's not a keyword then it's a name
					in_string = 0;
					token_type = Name;
					memcpy(
						output,
						expr + str_start_index,
						end_index - str_start_index+1
					);
					return output;
				}
			}
			else if (expr[i] == '*') {
				token_type = PointerTo;
				memcpy(output, expr+i, 1);
				output[1] = '\0';
				++i;
				return output;
			}
			else if (expr[i] == '(') {
			  int start = i+1;
			  if(expr[start] != '\0' && expr[start] == ')') {
			    token_type = FunctionCall;
			    memcpy(output, expr + start, 2);
			    output[2] = '\0';
			    i += 2;
			    return output;
			  }
			  
			  token_type = OpenParenthis;
			  memcpy(output, expr + i, 1);
			  output[1] = '\0';
			  ++i;
			  return output;
			}
			else if (expr[i] == ')') {
				token_type = CloseParenthis;
				memcpy(output, expr + i, 1);
				output[1] = '\0';
				++i;
				return output;
			}
			else if (expr[i] == ';') {
				token_type = EndOfLine;
				memcpy(output, expr + i, 1);
				output[1] = '\0';
				++i;
				return output;
			}
			else if (expr[i] == '[') {
				in_arr_syntax = 1;
				arr_syntax_start_index = i;
			}
			else if (expr[i] == ']') {
				token_type = ArrayBrackets;
				memcpy(output, expr + arr_syntax_start_index, i+1 - arr_syntax_start_index);
				++i;
				in_arr_syntax = 0;
				return output;
			}
		}
		else if (isalpha(expr[i]) && !in_string) {
			in_string = 1;
			str_start_index = i;
		}
	}

	return NULL;
}

void PrintBasedOnName(Tokens token) {
	switch (token)
	{
	case PointerTo:
		printf("pointer to ");
		break;
	case ArrayBrackets:
		printf("array of ");
		break;
	case FunctionCall:
		printf("function returning ");
		break;
	case Number:
		break;
	case TypeInt:
		printf("int");
		break;
	case TypeChar:
		printf("char");
		break;
	case TypeShort:
		printf("short");
		break;
	case TypeDouble:
		printf("double");
		break;
	case TypeFloat:
		printf("float");
		break;
	case TypeVoid:
	  printf("void");
	  break;
	case EndOfLine:
		break;
	case OpenParenthis:
		break;
	case CloseParenthis:
		break;
	default:
		break;
	}
}

Tokens GetTokenTypeByName(char* name) {
  if(strcmp(name, "int") == 0) {
    return TypeInt;
  }
  else if(strcmp(name, "char") == 0) {
    return TypeChar;
  }
  else if(strcmp(name, "short") == 0) {
    return TypeShort;
  }
  else if(strcmp(name, "double") == 0) {
    return TypeDouble;
  }
  else if(strcmp(name, "float") == 0) {
    return TypeFloat;
  }
  else if(strcmp(name, "void") == 0) {
    return TypeVoid;
  }

  return None;
}

// if it returns 0 it means that it did not find a size
int ExtractSize(char* token) {
  int result = 0;
  while(*token != '\0') {
    if(isdigit(*token)) {
      result = result * 10 + (*token - '0');
    }
    ++token;
  }

  return result;
}
