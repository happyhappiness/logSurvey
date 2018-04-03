#ifndef _MSWSOCK_
#include <mswsock.h>
#endif
#include <fde.h>

SQUIDCEXTERN LPCRITICAL_SECTION dbg_mutex;
void WIN32_ExceptionHandlerCleanup(void);
static LPTOP_LEVEL_EXCEPTION_FILTER Win32_Old_ExceptionHandler = NULL;


int WIN32_pipe(int handles[2])
{
    int new_socket;
