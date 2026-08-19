#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include "command.h"

Pipeline* parse(const Token* tokens);
void free_command(Command* command);
void free_pipeline(Pipeline* pipeline);

#endif
