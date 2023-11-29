#define MAX_NO_TOKENS 1000

typedef enum Tokens {
	None,
	PointerTo,
	ArrayBrackets,
	FunctionCall,
	Name,
	Number,
	TypeInt,
	TypeChar,
	TypeShort,
	TypeDouble,
	TypeFloat,
	TypeVoid,
	EndOfLine,
	OpenParenthis,
	CloseParenthis
} Tokens;

static int top = 0;
static Tokens tokens[MAX_NO_TOKENS];

void Push(Tokens token) {
	if (top < MAX_NO_TOKENS) {
		tokens[top++] = token;
	}
}

Tokens Pop(void) {
	if (top > 0) {
		return tokens[--top];
	}

	return None;
}
