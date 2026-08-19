#ifndef COMMAND_H
#define COMMAND_H

#include <stdbool.h>

/*
 *  Represents one executable command and the things modify how the commands are executed.
 *
 *  example : cat < input.txt > output.txt &
 *  
 *  so, the above command becomes something like : 
 *  	argv = {"cat", NULL}
 *  	input_file = input.txt;
 *  	output_file = output.txt;
 *  	background = true
 */
typedef struct
{
    int argc;
    char** argv;

    char* input_file;
    char* output_file;
    
    bool background;
}Command;

/*
 *  A pipeline in two or more commands, connected by '|'
 *  example :  ls | grep hot  is 2 commands : ls and grep hot
 */
typedef struct
{
    int command_count;
    Command** commands;
}Pipeline;

#endif
