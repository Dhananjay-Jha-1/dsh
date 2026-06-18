#ifndef BUILTINS_H
#define BUILTINS_H

int is_builtin(char* argv[]);
void exec_cd(char* argv[]);
void exec_exit(char* argv[]);
void exec_builtin(char* argv[]);

#endif
