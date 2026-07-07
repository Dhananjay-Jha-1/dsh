#ifndef TOKEN_H
#define TOKEN_H

typedef enum
{
    TOKEN_WORD,
    TOKEN_PIPE,
    TOKEN_REDIRECT_IN,
    TOKEN_REDIRECT_OUT,
    TOKEN_BACKGROUND,
    TOKEN_EOF,
}Token_Kind;

typedef struct
{
    Token_Kind kind;
    char* text;
}Token;

#endif
