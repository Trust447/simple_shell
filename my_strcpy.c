#include <stdio.h>
/**
* _stcpy - fuction that copies strings from one variable to another
*
* @copy : Destination
* @main : Source
* Returns void
*/

void _strcpy(char *copy, char *main)
{

	while (*main != '\0')
	{
		*copy = *main;
		copy++;
		main++;
	}
	*copy = '\0';
}
