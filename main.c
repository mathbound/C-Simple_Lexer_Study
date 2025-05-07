#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main(int argc, char* argv[]){

    (void)argc;
    (void)argv;

    printf("Tokenizer in C\n");

    Token *tok = malloc(sizeof *tok);
    src = "   a   ";//3_SPACE UNK 3_SPACE EOF
    pos = 0;
    do {
        next_token(tok);
        printf("Token: type=%d, text='%s'\n", tok->type, tok->text);
    } while (tok->type != TOK_EOF);
    free(tok);
    return 0;
}
