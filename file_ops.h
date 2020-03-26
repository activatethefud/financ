#ifndef __FILE_OPTS_H
#define __FILE_OPTS_H

#define _XOPEN_SOURCE 500
//#define _POSIX_C_SOURCE 200809

int parse_file(const char *path,int (*parse_line)(const char*));
int parse_file_extra(const char *path,int (*parse_line)(char*,void*));
const char* append_to_file(const char *fpath, const char* string);
float range_query(const char *path,const char *date_from,const char *date_to,float (*parse_line)(char*));

#endif
