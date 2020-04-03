#include "report.h"
#include "file_ops.h"
#include "main.h"

float sum_outflow(char *line)
{
	int io_flag;
	char *token;
	float amount;

	int tokenizer_size;
	char **tokenizer = create_tokenizer(line,&tokenizer_size,DELIMITER);

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
	char **tokenizer = create_tokenizer(line,&tokenizer_size,DELIMITER);

	io_flag=strtol(tokenizer_get_field(tokenizer,tokenizer_size,IO_FIELD),NULL,10);
	amount = strtof(tokenizer_get_field(tokenizer,tokenizer_size,AMOUNT_FIELD),NULL);

	delete_tokenizer(tokenizer,tokenizer_size);
	return (io_flag == 1)*amount;
}
