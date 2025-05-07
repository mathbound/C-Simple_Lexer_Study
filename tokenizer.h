#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string.h>
#include <ctype.h>

typedef enum{
    TOK_EOF = 0,
    TOK_SPACE = 1,
    TOK_UNK = 2,
}TokenType;

typedef struct{
    TokenType type;
    char text[128];
}Token;

extern const char *src;
extern size_t pos;

void next_token(Token* tok);

#endif //TOKENIZER_H
