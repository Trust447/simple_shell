#include "main.h"
#include "envhead.h"

/**
 * cust_evn - get env
 * @cenvname: pointer cenvname
 * Return: 0 on success
 */


char *cust_evn(const char *cenvname)
{
/*get access to the env variable*/

int strcmpvalue;
int lengthofthepath;
int ct;
lengthofthepath = strlen(cenvname);

for (ct = 0; environ[ct] != NULL; ct++) /*Looping through the env variable*/
{
strcmpvalue = strncmp(environ[ct], cenvname, lengthofthepath);

if (strcmpvalue == 0 && environ[ct][lengthofthepath] == '=')
{
return (environ[ct] + lengthofthepath + 1);
}

}

return (NULL);
}

