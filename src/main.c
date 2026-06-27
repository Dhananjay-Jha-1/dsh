#include "shell.h"
#include "signals.h"

int main(void)
{
    setup_handler();
    
    start_shell();
    
    return 0;
}
