#ifndef ERRORS_H
#define ERRORS_H

#include "main.h"

#define ASSERT(cond,msg) Error(cond,msg,__FILE__,__LINE__)

void Error(const int cond, const char *msg, const char *file, const int line);

#endif
