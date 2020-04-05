#include "file_ops.h"

int parse_file(const char *path,int (*parse_line)(const char*))
{
		char *line=NULL;
		size_t lineBuf=0;
		FILE *input=fopen(path,"r");

		if(input == NULL) {
				return -1;
		}
		int i=0;

		while(getline(&line,&lineBuf,input) > 0) {
				(*parse_line)(line);
		}

		free(line);
		fclose(input);
		return 0;
}

float range_query(const char *path,const char *date_from,const char *date_to,float (*parse_line)(char*))
{
		char *line=NULL;
		size_t line_buf=0;
		float result=0;
		FILE *input=fopen(path,"r");

		ASSERT(NULL != input,"Error opening range query file");

		time_t date_1 = mktime(getdate(date_from));
		time_t date_2 = mktime(getdate(date_to));

		while(getline(&line,&line_buf,input) > 0) {

				ASSERT(date_2 > date_1,"`From` date after `to` date!");

				char *temp = strdup(line);
				time_t date_3 = mktime(getdate(strtok(temp,DELIMITER)));
				free(temp);

				if(date_1 <= date_3 && date_3 <= date_2) {
					result += (*parse_line)(line);
				}

		}

		free(line);
		fclose(input);
		return result;
}

float category_range_query(const char *path,const char *date_from,const char *date_to,const char *categ_name,float (*parse_line)(char*))
{
		char *line=NULL;
		size_t line_buf=0;
		float result=0;

		FILE *input=fopen(path,"r");
		ASSERT(NULL != input,"Error opening range query file");

		char **tokenizer;
		int tokenizer_size;

		time_t date_1 = mktime(getdate(date_from));
		time_t date_2 = mktime(getdate(date_to));

		while(getline(&line,&line_buf,input) > 0) {

				tokenizer = create_tokenizer(strdup(line),&tokenizer_size,DELIMITER);

				ASSERT(date_2 > date_1,"'From' date after 'to' date!");

				time_t date_3 = mktime(getdate(tokenizer_get_field(tokenizer,tokenizer_size,DATE_FIELD)));

				if(date_1 <= date_3 && date_3 <= date_2 && !strcmp(categ_name,tokenizer_get_field(tokenizer,tokenizer_size,CATEG_FIELD))) {
					result += (*parse_line)(line);
				}

				delete_tokenizer(tokenizer,tokenizer_size);
		}

		free(line);
		fclose(input);
		return result;
}

const char* append_to_file(const char *fpath, const char* string)
{
		FILE *output=fopen(fpath,"a");

		ASSERT(NULL != output,"Error opening append file!");
		ASSERT(EOF != fputs(string,output),"Appening to file failed!");

		fclose(output);

		return string;
}

char **create_tokenizer(char *line,int *tokenizer_size,const char *delimiter)
{
	*tokenizer_size = 0;
	char **tokenizer = malloc(sizeof *tokenizer);
	char *token;

	while((*tokenizer_size == 0 && (token=strtok(line,delimiter))) || (token=strtok(NULL,delimiter))) {

		tokenizer[(*tokenizer_size)++] = token;
		ASSERT(NULL != (tokenizer = realloc(tokenizer,(*tokenizer_size+1)*(sizeof *tokenizer))),"Realloc failed");
	}

	return tokenizer;
}

char *tokenizer_get_field(char **tokenizer,int tokenizer_size,int index)
{
	ASSERT(index < tokenizer_size,"Index exceeds tokenizer size");
	return tokenizer[index];
}

void delete_tokenizer(char **tokenizer,int tokenizer_size)
{
	free(tokenizer[0]);
	free(tokenizer);
}
