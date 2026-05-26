#include <stdio.h>

#include "parser.h"

void print_token(char* argv[], int argc)
{
    for(int i = 0; i < argc; i++)
    {
        printf("Token %d : %s\n", i, argv[i]); 
    }
}

void parse_input(char* input)
{
    char* argv[64];
    int argc = 0; 
    int i = 0;
    
    while(input[i] != '\0')
    {
        while(input[i] == ' ')
        {
            i++;
        }

     	if(input[i] == '\0')
		{
		    break;
		}

        argv[argc] = &input[i];
        argc++;

        while(input[i] != ' ' && input[i] != '\0')
        {
            i++;
        }

        while(input[i] == ' ')
        {
            input[i] = '\0';
	    i++;
        }
    }
    argv[argc] = NULL;

    print_token(argv, argc);    
}
