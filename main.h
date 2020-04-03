#ifndef MAIN_H
#define MAIN_H

#define _XOPEN_SOURCE 500
//#define _POSIX_C_SOURCE 200112L
#define _POSIX_C_SOURCE 200809L
#include "callbacks.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <libgen.h>
#include "llist.h"
#include "utility.h"
#include "file_ops.h"
#include "errors.h"
#include "report.h"
#define GETOPT_FMT "ha:ioc:d:"
#define DELIMITER ",\n"
#define DATE_FMT "dd/mm/yyyy"

#define BUDGET_FILE "budget.txt"
#define TRANSAC_FILE "history.txt"
#define HIDDEN_CATEG_FILE "hidden.txt"
#define DATA_DIR "/.config/financ/"

#define DATE_FIELD (0)
#define IO_FIELD (1)
#define CATEG_FIELD (2)
#define AMOUNT_FIELD (3)
#define DESCR_FIELD (4)

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
