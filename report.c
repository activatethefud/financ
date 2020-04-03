#include "report.h"
#include "main.h"

float sum_outflow(char *line)
{
	int io_flag;
	char *token;
	float amount;

	// Skip date
	free(strtok(line,DELIMITER));
	token = strtok(NULL,DELIMITER);
	io_flag=strtol(token,NULL,10);

	free(token);

	// Skip category
	free(strtok(NULL,DELIMITER));

	token=strtok(NULL,DELIMITER);
	amount = strtof(token,NULL);
	free(token);

	if(io_flag == 1) {
		return amount;
	}

	return 0;
}
