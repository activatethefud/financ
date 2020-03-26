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

// Globals
//node *categories=NULL;
//node *hidden_categories=NULL;
//unsigned line_counter=0;
//float global_sum=0;
//int global_int=0;
//int monthly_inflow=0;
//int monthly_outflow=0;
//float outflow=0;
//int transac_counter=0;
//char *monthly_outflow_date;
//char *category_global;

#endif
