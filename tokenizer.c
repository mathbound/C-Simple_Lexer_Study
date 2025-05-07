#include "tokenizer.h"

const char *src = NULL;
size_t pos = 0;


void next_token(Token* tok){
    if (isspace((unsigned char)src[pos])) {
        size_t start = pos;
        while (isspace((unsigned char)src[pos])) pos++;
        size_t len = pos - start;
        strncpy(tok->text, src + start, len);
        tok->text[len] = '\0';
        tok->type = TOK_SPACE;
        return;
    }
    if (src[pos] == '\0') {
        tok->type = TOK_EOF;
        tok->text[0] = '\0';
        return;
    }

    tok->text[0] = src[pos++];
    tok->text[1] = '\0';
    tok->type = TOK_UNK;
}
