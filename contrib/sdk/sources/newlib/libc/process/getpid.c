#include <process.h>
#include <sys/ksys.h>

unsigned getpid(void)
{
    ksys_thread_t t;

    _ksys_thread_info(&t, -1);

    return t.pid;
}
