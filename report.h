#ifndef REPORT_H
#define REPORT_H

#include "file_ops.h"

float sum_outflow(char *line);
float sum_inflow(char *line);
float count_occurrence_outflow(char *line);
float interval_outflow(char *line);

#endif
