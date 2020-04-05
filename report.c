#include "report.h"

float sum_outflow(char *line)
{
	int io_flag;
	char *token;
	float amount;

	int tokenizer_size;
	char **tokenizer = create_tokenizer(strdup(line),&tokenizer_size,DELIMITER);

	io_flag=strtol(tokenizer_get_field(tokenizer,tokenizer_size,IO_FIELD),NULL,10);
	amount = strtof(tokenizer_get_field(tokenizer,tokenizer_size,AMOUNT_FIELD),NULL);

	delete_tokenizer(tokenizer,tokenizer_size);
	return (!io_flag)*amount;
}

float sum_inflow(char *line)
{
	int io_flag;
	char *token;
	float amount;

	int tokenizer_size;
	char **tokenizer = create_tokenizer(strdup(line),&tokenizer_size,DELIMITER);

	io_flag=strtol(tokenizer_get_field(tokenizer,tokenizer_size,IO_FIELD),NULL,10);
	amount = strtof(tokenizer_get_field(tokenizer,tokenizer_size,AMOUNT_FIELD),NULL);

	delete_tokenizer(tokenizer,tokenizer_size);
	return (io_flag == 1)*amount;
}

#define DAY (3600*24)
float count_occurrence_outflow(char *line)
{
	static time_t last = 0;
	static time_t current = 0;

	int tokenizer_size;
	char **tokenizer = create_tokenizer(strdup(line),&tokenizer_size,DELIMITER);

	char *io_flag = tokenizer_get_field(tokenizer,tokenizer_size,IO_FIELD);
	char is_outflow = io_flag[0] == '0';

	if(!is_outflow) {
		return 0;
	}

	if(!last) {
		last = mktime(getdate(tokenizer_get_field(tokenizer,tokenizer_size,DATE_FIELD)));
	}
	else {
		current = mktime(getdate(tokenizer_get_field(tokenizer,tokenizer_size,DATE_FIELD)));
		float diff = current - last;
		last = current;

		if(!diff) {
			delete_tokenizer(tokenizer,tokenizer_size);
			return 0;
		}
	}

	delete_tokenizer(tokenizer,tokenizer_size);
	return 1;
}

float interval_outflow(char *line)
{
	static time_t last = 0;
	static time_t current = 0;

	int tokenizer_size;
	char **tokenizer = create_tokenizer(strdup(line),&tokenizer_size,DELIMITER);

	char *io_flag = tokenizer_get_field(tokenizer,tokenizer_size,IO_FIELD);

	if(io_flag[0] != '0') {
		delete_tokenizer(tokenizer,tokenizer_size);
		return 0;
	}

	if(!last) {
		last = mktime(getdate(tokenizer_get_field(tokenizer,tokenizer_size,DATE_FIELD)));
		delete_tokenizer(tokenizer,tokenizer_size);
		return 0;
	}
	else {
		current = mktime(getdate(tokenizer_get_field(tokenizer,tokenizer_size,DATE_FIELD)));
		float diff = current-last;

		last = current;
		delete_tokenizer(tokenizer,tokenizer_size);
		return diff/DAY;
	}
	
}
