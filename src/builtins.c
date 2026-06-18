#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <builtins.h>

int is_builtin(char* argv[])
{
    if(argv[0] == NULL)
        return -1;

    if(strcmp(argv[0], "cd") == 0)
        return 1;
    else if(strcmp(argv[0], "exit") == 0)
        return 1;

    else
        return 0;
}

void exec_builtin(char* argv[])
{
    if(strcmp(argv[0], "cd") == 0)
    {
        exec_cd(argv);
    } 
    if(strcmp(argv[0], "exit") == 0)
    {
        exec_exit(argv);
    }
}

void exec_cd(char* argv[])
{
    char cwd[256];
    if(strcmp(argv[0], "cd") == 0)
    {
        char* directory = argv[1];
        int ret;

        ret = chdir(directory);
        
        if(argv[1] == NULL)
        {
            char* home = getenv("HOME");
            int ret1 = chdir(home);
            
            if(ret1 == -1)
                perror("home");
            else
            {
                if(getcwd(cwd, sizeof(cwd)) == NULL)
                    perror("error");
                //else
                  // printf("You are at : %s\n", cwd);
            }
            return;
        }

        if(ret == -1)
        {
            perror("cd");
            return;
        }
        else
        {
            if(getcwd(cwd, sizeof(cwd)) == NULL)
                perror("error");
            //else
              //  printf("You are at : %s\n", cwd);
        }
    }
}

void exec_exit(char* argv[])
{
    //code for exit 
}
