#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include "llist.h"
#include <stdio.h>

typedef struct {
	char *name;
	float state;
	float plan;
	float budgeted;
} category;

typedef struct {
	time_t date;
	int io_flag;
	char* categ;
	float amount;
} transac_line;

#endif
