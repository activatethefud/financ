#include "callbacks.h"

extern float global_sum;
extern int global_int;

void sum_state(const void *data)
{
                // Multiply to skip summing for Debt category
		global_sum += ((category*)data) -> state * (strcmp(((category*)data)->name,"Debt") != 0);
}
void sum_budgeted(const void *data)
{
	global_sum += ((category*)data)->budgeted;
}
void sum_unbudgeted(const void *data)
{
		int unbudgeted=((category*)data)->plan - ((category*)data)->budgeted;
		global_sum += (unbudgeted > 0)*unbudgeted;
}
void sum_plan(const void *data)
{
		global_sum += ((category*)data) -> plan;
}
void max_len_check(const void *data)
{
		category *categ=(category*)data;
		int len=strlen(categ->name);

		if(len > global_int) {
				global_int=len;
		}
}
