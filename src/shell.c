#include <stdio.h>
#include <string.h>

#include "shell.h"
#include "parser.h"
#include "executor.h"

void start_shell(void)
{
    char input[1024];
    char* argv[64];

    while(1)
    {
        // prompt to wait for user input
        printf("dsh> ");
        fflush(stdout);

        // handling CTRL + D 
        if(fgets(input, sizeof(input), stdin) == NULL)
        {
            break;
        }

        //now fgets also store the '\n' character i will have to remove it
        int n = strlen(input);

        for(int i = 0; i < n; i++)
        {
            if(input[i] == '\n')
            {
                input[i] = '\0';
                break;
            }
        }
        int argc = parse_input(input, argv);
        
        execute(argc, argv);
    }
}
