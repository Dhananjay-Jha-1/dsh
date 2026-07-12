#ifndef LEXER_H
#define LEXER_H

#include "token.h"

Token* lexer(const char* input);
void free_tokens(Token* tokens);

#endif
