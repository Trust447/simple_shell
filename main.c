#include"main.h"
#include"funcs.h"

/**
*main-theentrypoint
*@argv:agruementvector
*@argc:argumentcounter
*@sysenvp:envpathvariable
*Return:0onsuccess
*/

int main(int argc, char**argv, char**sysenvp)
{
/*declaringvarialefortheprogram*/
char*prompt="Group(shell)$";
int from_pipe = 1;
ssize_t linelen;
char*buf=NULL;
char*str=NULL;
int tok_count=0;
size_t number=0;
int agccount=0;
while (from_pipe == 1)
{
if (isatty(STDIN_FILENO)==0)/*thiscodesectioncheckiffileispiped*/
from_pipe = 2;

write(STDOUT_FILENO,prompt,strlen(prompt));/*writingouttocommandpromt*/

linelen = readline(&buf,&number);
str = creatingmemory(linelen);
cpstrcpy(str,buf);/*usingcustomstringcopy*/
tokenizeInput(buf,&argv,&argc);

while(agccount<argc)
agccount++;

if(strcmp(argv[0],"exit")==0)
managetheExitCmd(argc,argv);
else if(strcmp(argv[0],"env")==0)
manageEnvVariable(sysenvp);
else if(strcmp(argv[0],"setenv")==0)
{
if(argc>=3)

setenv_op(argv[1], argv[2]);

else

write(STDERR_FILENO,"Syntaxerror:setenvrequiresatleasttwoarguments\n",52);

}

else if(strcmp(argv[0],"unsetenv")==0)
{
if(argc>=2)

unsetenv_op(argv[1]);

else
write(STDERR_FILENO,"unsetenvrequiresatleastoneargument\n",52);

}
else

managingFilesPath(argv);
free_memory(buf,str,argv,tok_count);

}
return(0);
}
