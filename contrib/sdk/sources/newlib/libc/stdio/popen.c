#include <stdio.h>
#include <sys/ksys.h>

FILE *popen(const char *command, const char *type)
{
    pid_t p = _ksys_exec(command, "", false);

    if(p < 0)
        return NULL;
    
}
