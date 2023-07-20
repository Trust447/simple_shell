#include "main.h"

/**
* count_tok - Counts the number of words tokenized
*
*  cmd_cpy : copy of line to be tokenized
*
*  deli : delimiter
*
*  Return: c count of the token
*/

int count_tok(char* cmd_cpy, char* deli)
{
	 char* tok;
	 int c = 0;
	 tok = strtok(cmd_cpy, deli);
	 while (tok != NULL)
	{
		c++;
		tok = strtok(NULL, deli);
	}
	 return (c);
}
