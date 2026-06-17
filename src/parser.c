#include <stdio.h>
#include "parser.h"

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
