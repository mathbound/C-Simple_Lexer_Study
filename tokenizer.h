#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string.h>
#include <ctype.h>

typedef enum{
    TOK_EOF,
    TOK_SPACE,
    TOK_UNK,
}TokenType;

typedef struct{
    TokenType type;
    char text[128];//maybe its too big?
}Token;

void next_token(Token* tok);

#endif //TOKENIZER_H
