#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "shell.h"
#include "builtins.h"
#include "parser.h"
#include "executor.h"

#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void start_shell(void)
{
    char input[1024];
    char* argv[64];

    while(1)
    {
        // prompt to wait for user input
        char* cwd = getcwd(NULL, 0);      // now this allocates memory for current directory using malloc 
        printf(ANSI_COLOR_GREEN "dsh>@%s $ " ANSI_COLOR_RESET, cwd);
        fflush(stdout);

        free(cwd);

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
        
        if(argc == 0)
            continue;
        if(is_builtin(argv))
            exec_builtin(argv);
        else
            execute(argc, argv);
    }
}
