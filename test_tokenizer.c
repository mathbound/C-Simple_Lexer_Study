#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "tokenizer.h"

void run_test(const char *input, TokenType expected_type, const char *expected_text) {
    src = input;
    pos = 0;
    Token tok;
    next_token(&tok);
    assert(tok.type == expected_type);
    assert(strcmp(tok.text, expected_text) == 0);
}

int main(void) {
    // Test whitespace
    run_test("   ", TOK_SPACE, "   ");
    // Test EOF
    run_test("", TOK_EOF, "");
    // Test UNK
    run_test("a", TOK_UNK, "a");
    // combination
    src = " \tX"; pos = 0;
    Token tok;
    next_token(&tok);
    assert(tok.type == TOK_SPACE && strcmp(tok.text, " \t") == 0);
    next_token(&tok);
    assert(tok.type == TOK_UNK && strcmp(tok.text, "X") == 0);
    next_token(&tok);
    assert(tok.type == TOK_EOF);

    printf("All tests passed.\n");
    return 0;
}
