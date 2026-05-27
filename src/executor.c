#include <stdio.h>

#include "executor.h"

//first let's check by printing if it works at all
void execute(char* argv[])
{
    for(int i = 0; argv[i] != NULL; i++)
    {
        printf("Token %d : %s\n", i, argv[i]);
    }
}
