#ifndef __FILE_OPTS_H
#define __FILE_OPTS_H

#define _XOPEN_SOURCE 500
#include "main.h"

#define DAY (3600*24)

int parse_file(const char *path,int (*parse_line)(const char*));
int parse_file_extra(const char *path,int (*parse_line)(char*,void*));
const char* append_to_file(const char *fpath, const char* string);
float range_query(const char *path,const char *date_from,const char *date_to,float (*parse_line)(char*));
float category_range_query(const char *path,const char *date_from,const char *date_to,const char *categ_name,float (*parse_line)(char*));

// Tokenizer functions
char **create_tokenizer(char *line,int *tokenizer_size,const char *delimiter);
char *tokenizer_get_field(char **tokenizer,int tokenizer_size,int index);
void delete_tokenizer(char **tokenizer,int tokenizer_size);

#endif
