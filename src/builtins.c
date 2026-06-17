#include <string.h>

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

int exec_builtin(char* argv[])
{

}
