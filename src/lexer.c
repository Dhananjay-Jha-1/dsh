#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "token.h"

#define MAX_TOKENS  128

static bool is_operator(char c)
{
    return c == '|' 
        || c == '<' 
        || c == '>' 
        || c == '&';
}

static bool is_whitespace(char c)
{
    return c == ' ';
}

static void skip_whitespaces(const char* input, int* i)
{
    while(is_whitespace(input[*i]))
    {
        (*i)++;
    }
}


static Token lex_word(const char* input, int* i)
{
    Token token = {
        .kind = TOKEN_WORD,
        .text = NULL
    };

    int length = 0;
    int start = *i;
    while(input[*i] != '\0'
          && !is_whitespace(input[*i])
          && !is_operator(input[*i]))
    {
        (*i)++;
    }
    length = *i - start;
    
    token.text = malloc(length + 1);
    
    if(token.text == NULL)
    {
        perror("malloc");
        exit(1);
    }

    memcpy(token.text, &input[start], length);

    token.text[length] = '\0';

    return token;
}

static Token lex_operator(const char* input, int* i)
{
    Token token = {
        .kind = TOKEN_EOF,
        .text = NULL
    };

    if(input[*i] == '|')
    {
        token.kind = TOKEN_PIPE;
    }
    else if(input[*i] == '<')
    {
        token.kind = TOKEN_REDIRECT_IN;
    }
    else if(input[*i] == '>')
    {
        token.kind = TOKEN_REDIRECT_OUT;
    }
    else if(input[*i] == '&')
    {
        token.kind = TOKEN_BACKGROUND;
    }
    
    token.text = NULL;
    (*i)++;

    return token;
}

void free_tokens(Token* tokens)
{
    int i = 0;

    if(tokens == NULL)
    {
        return;
    }

    while(tokens[i].kind != TOKEN_EOF)
    {
        free(tokens[i].text);
        i++;
    }
    free(tokens);
}

Token* lexer(const char* input)
{
    int i = 0;
    
    Token* tokens = malloc(MAX_TOKENS * sizeof(Token));
    
    int token_count = 0;

    if(tokens == NULL)
    {
        perror("malloc");
        exit(1);
    }

    while(input[i] != '\0')
    {
        skip_whitespaces(input, &i);

        if(input[i] == '\0')
        {
            break;
        }

        if(is_operator(input[i]))
        {
            tokens[token_count] = lex_operator(input, &i);
            token_count++;
        }

        else
        {
            tokens[token_count] = lex_word(input, &i);
            token_count++;
        }
    }
    tokens[token_count] = (Token){
        .kind = TOKEN_EOF,
        .text = NULL
    };

    return tokens;
}


