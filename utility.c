#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

char *read_string() {
		char ch;
		int bufSize=19;
		int counter=0;
		char *string=malloc(bufSize);

		while((ch=getchar()) != EOF && ch != '\n') {
				if(counter == bufSize) {
						bufSize *= 2;
						string=realloc(string,bufSize);
				}
				string[counter++]=ch;
		}

		return string;
}

int print_string(const char *string)
{
		int i=0;

		while(string[i] != '\0') {
				printf("%c",string[i++]);
		}
		printf("\n");
}
