// so what I have to do here is simply do lexical analysis 
// ls -la | grep   -->   WORD("ls") WORD("-la")  PIPE   WORD("grep")  EOF

// now how do I do this, lets create the 1st version for word and pipe first

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

#define MAX_LENGTH_OF_TOKEN  128

void lexer(char* input)
{
    int i = 0;

    while(input[i] != '\0')
    {
        while(input[i] == ' ')
        {
            i++;
        }

        if(input[i] == '|')
        {
            Token* token = malloc(sizeof(Token));

            token->kind = TOKEN_PIPE;
            token->text = NULL;

            printf("%d( %s)\n", token->kind, token->text);

            i++;
        }

        else if(input[i] != ' ' && input[i] != '|')
        {
            Token* token = malloc(sizeof(Token));   // toh space allocate kr diya, ek struct object bn gya 

            token->kind = TOKEN_WORD;
            
            // ab token->text me wo string daalna h jo mila
            int count = 0;
            for(int j = i; input[j] != '\0'; j++)
            {
                if(input[j] == ' ' || input[j] == '|')
                {
                    break;
                }
                if(input[j] != ' ')
                {
                    count++;
                }
            }
            token->text = malloc(count + 1);
            memcpy(token->text, &input[i], count);

            token->text[count] = '\0';

            printf("%d( %s)\n", token->kind, token->text);

            i = i+count;
        }
    }
}
