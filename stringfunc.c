#include "main.h"

/**
 * cstrlen - handles length of string
 * @value: takes count of argument passed to the program
 *
 * Return: 0 on success
 */


size_t cstrlen(const char *value)
{
	/*checking for strng fuc*/
	size_t leng = 0;

	/*check and print out each arguments*/
	while (value[leng] != '\0')
	{
		leng++;
	}
	return (leng);
}



/**
 * cpstrcpy - handles copy function
 * @finaldes: destination where texts are copied to
 * @strsource: source of the text copied
 * Return: finaldes on success
 */

char *cpstrcpy(char *finaldes, const char *strsource)
{
	/*checking for strng fuc*/
	int countingnum = 0;

	/*check and print out each arguments*/
	while (strsource[countingnum] != '\0')
	{
		finaldes[countingnum] = strsource[countingnum];
countingnum++;

	}
finaldes[countingnum] = '\0';
	return (finaldes);
}

/**
 * cstrconcat - this handles string concetination
 *
 * @filepath: pointer to the path of file
 * @additionpath: command passed from get line
 * Return: 0 on success
 */

char *cstrconcat(char *filepath, const char *additionpath)
{
	int filelength = 0;
	int fircnt = 0, secnt = 0;

	while (filepath[filelength] != '\0')
	{
		++filelength;
	}

	for (secnt = 0; additionpath[secnt] != '\0'; ++secnt, ++filelength, ++fircnt)
	{
		filepath[filelength] = additionpath[fircnt];
	}
	return (filepath);

}
