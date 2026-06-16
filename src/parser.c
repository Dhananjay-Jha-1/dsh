#include <stdio.h>

#include "parser.h"

//toh ab krna kuch aisa h ki parse_input() function ka argv executor.c me dena h
// how do I do it, now?

int parse_input(char* input, char* argv[])
{
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
    
    return argc;
}
