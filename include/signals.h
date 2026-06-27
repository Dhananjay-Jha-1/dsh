#ifndef SIGNALS_H
#define SIGNALS_H

#include "sys/types.h"

void handler(int sig);
void setup_handler(void);

extern pid_t foreground_pid;

#endif
