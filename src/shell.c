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
        printf("dash> ");

        fgets(input, sizeof(input), stdin);

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

        parse_input(input, argv);

        execute(argv);        
    }
}
