#include"main.h"
#include"funcs.h"

/**
*main-theentrypoint
*@argv:agruementvector
*@argc:argumentcounter
*@sysenvp:envpathvariable
*Return:0onsuccess
*/

intmain(intargc,char**argv,char**sysenvp)
{
/*declaringvarialefortheprogram*/
char*prompt="Group(shell)$";
intfrom_pipe=1;
ssize_tlinelen;
char*buf=NULL;
char*str=NULL;
inttok_count=0;
size_tnumber=0;
intagccount=0;
while(from_pipe==1)
{
if(isatty(STDIN_FILENO)==0)/*thiscodesectioncheckiffileispiped*/
from_pipe=2;

write(STDOUT_FILENO,prompt,strlen(prompt));/*writingouttocommandpromt*/

linelen=readline(&buf,&number);
str=creatingmemory(linelen);
cpstrcpy(str,buf);/*usingcustomstringcopy*/
tokenizeInput(buf,&argv,&argc);

while(agccount<argc)
agccount++;

if(strcmp(argv[0],"exit")==0)
managetheExitCmd(argc,argv);
elseif(strcmp(argv[0],"env")==0)
manageEnvVariable(sysenvp);
elseif(strcmp(argv[0],"setenv_op")==0)
{
if(argc>=3)

setenv_op(argc,argv);

else

write(STDERR_FILENO,"Syntaxerror:setenvrequiresatleasttwoarguments\n",52);

}

elseif(strcmp(argv[0],"unsetenv")==0)
{
if(argc>=2)

unsetenv_op(argc,argv);

else
write(STDERR_FILENO,"unsetenvrequiresatleastoneargument\n",52);

}
else

managingFilesPath(argv);
free_memory(buf,str,argv,tok_count);

}
return(0);
}
