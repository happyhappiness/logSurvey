#include "SquidTime.h"
#include "Store.h"

fde *fde::Table = NULL;

bool
fde::readPending(int fdNumber)
{
    if (type == FD_SOCKET)
        return Comm::MonitorsRead(fdNumber);

    return read_handler ? true : false ;
}

void
fde::dumpStats (StoreEntry &dumpEntry, int fdNumber)
{
    if (!flags.open)
        return;

#if _SQUID_WINDOWS_

    storeAppendPrintf(&dumpEntry, "%4d 0x%-8lX %-6.6s %4d %7" PRId64 "%c %7" PRId64 "%c %-21s %s\n",
                      fdNumber,
                      win32.handle,
