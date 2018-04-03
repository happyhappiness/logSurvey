#pragma implementation
#endif

#include "config.h"
#include "signal.hh"

//#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <memory.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
//#include <signal.h>

SigFunc*
Signal( int signo, SigFunc* newhandler, bool doInterrupt )
