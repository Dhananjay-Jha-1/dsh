#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "command.h"

static int count_command_words(const Token *tokens, int start)
{
    int count = 0;

    while(tokens[start + count].kind == TOKEN_WORD)
    {
        count++;
    }

    return count;
}

static int count_commands(const Token* tokens)
{
    int count = 1;      // cuz, for eg. "ls" is already one command
    
    for(int i= 0; tokens[i].kind != TOKEN_EOF; i++)
    {
	if(tokens[i].kind == TOKEN_PIPE)
	{
	    count++;
	}
    }
    
    return count;
}

static void parse_command(const Token *tokens, int start, Command *command)
{
    int argc = count_command_words(tokens, start);

    command->argc = argc;

    command->argv = malloc((argc + 1) * sizeof *command->argv);

    if(command->argv == NULL)
    {
        perror("malloc");
        exit(1);
    }

    for(int i = 0; i < argc; i++)
    {
        command->argv[i] = malloc(strlen(tokens[start + i].text) + 1);

        if(command->argv[i] == NULL)
        {
            perror("malloc");
            exit(1);
        }

        strcpy(command->argv[i], tokens[start + i].text);
    }

    command->argv[argc] = NULL;
}

static int find_next_command(const Token* tokens, int start)
{
    while(tokens[start].kind != TOKEN_EOF &&
	  tokens[start].kind != TOKEN_PIPE)
    {
	start++;
    }

    if(tokens[start].kind == TOKEN_PIPE)
    {
	start++;
    }

    return start;
}

Pipeline* parse(const Token* tokens)
{
    int command_count = count_commands(tokens);

    Pipeline* pipeline = malloc(sizeof *pipeline);

    if(pipeline == NULL)
    {
	perror("malloc");
	exit(1);
    }

    pipeline->command_count = command_count;
    
    pipeline->commands = malloc(command_count * sizeof *pipeline->commands);

    if(pipeline->commands == NULL)
    {
	perror("malloc");
	free(pipeline);
	exit(1);
    }

    for(int i = 0; i < command_count; i++)
    {
	pipeline->commands[i] = malloc(sizeof *pipeline->commands[i]);

	if(pipeline->commands[i] == NULL)
	{
	    perror("malloc");
	    exit(1);
	}
    }
    
    int start = 0;
    for(int i = 0; i < command_count; i++)
    {
	parse_command(tokens, start, pipeline->commands[i]);

	start = find_next_command(tokens, start);
    }

    return pipeline;
}

void free_command(Command* command)
{
    if(command == NULL)
    {
	return;
    }

    for(int i = 0; i < command->argc; i++)
    {
	free(command->argv[i]);
    }
    
    free(command->argv);
    free(command);
}

void free_pipeline(Pipeline *pipeline)
{
    if(pipeline == NULL)
    {
        return;
    }

    for(int i = 0; i < pipeline->command_count; i++)
    {
        free_command(pipeline->commands[i]);
    }

    free(pipeline->commands);
    free(pipeline);
}


