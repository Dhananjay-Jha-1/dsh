#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "signals.h"

pid_t foreground_pid = -1; 

void handler(int sig)
{
    (void) sig;   // the variable is unused, this statement is added to fix the gcc warning

    if(foreground_pid > 0)
    {
        kill(foreground_pid, SIGINT);
    }
}

void setup_handler(void)
{
    struct sigaction sa = {0};
    
    sa.sa_handler = handler;

    sigemptyset(&sa.sa_mask);

    sa.sa_flags = 0;

    if(sigaction(SIGINT, &sa, NULL) == -1)
    {
        perror("sigaction");
    }
}


