#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "executor.h"
#include "signals.h"

int execute(int argc, char* argv[])
{
    /*for(int i = 0; argv[i] != NULL; i++)
    {
        printf("Token %d : %s\n", i, argv[i]);
    }
    printf("The number of tokens are : %d\n", argc);*/
    
    pid_t pid;
    pid = fork();
    
    if(pid == -1)
    {
        perror("fork failed");
        return -1;
    }
    else if(pid > 0)
    {
        //parent process
        foreground_pid = pid;
        waitpid(pid, NULL, 0);
        foreground_pid = -1;
    }
    else 
    {
        //child process when pid = 0
        execvp(argv[0], argv);
        
        perror( "\n dsh");
        exit(EXIT_FAILURE);
    }

    return argc;
}


