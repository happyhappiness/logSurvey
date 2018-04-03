 */

#include "squid.h"

char *
storeSwapFullPath(sfileno f, char *buf)
{
    return storeUfsFullPath(f, buf);
}

/*
