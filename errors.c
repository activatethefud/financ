#include "errors.h"

void Error(const int cond, const char *msg, const char *file, const int line)
{
		if(!cond) {
				perror(msg);
				fprintf(stderr,"%s: %d\n",file,line);
				exit(EXIT_FAILURE);
		}
}
