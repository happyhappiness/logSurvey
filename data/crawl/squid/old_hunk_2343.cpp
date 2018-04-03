 *
 */

#include "squid.h"
#include "comm.h"
#include "comm/Connection.h"
#include "comm/Loops.h"
#include "CommRead.h"
#include "fde.h"

DeferredReadManager::~DeferredReadManager()
{
    /* no networked tests yet */
}

DeferredRead::DeferredRead (DeferrableRead *, void *, CommRead const &)
{
    fatal ("Not implemented");
}

void
DeferredReadManager::delayRead(DeferredRead const &aRead)
{
    fatal ("Not implemented");
}

void
DeferredReadManager::kickReads(int const count)
{
    fatal ("Not implemented");
}

void
comm_read(const Comm::ConnectionPointer &conn, char *buf, int size, IOCB *handler, void *handler_data)
{
    fatal ("Not implemented");
}

void
comm_read(const Comm::ConnectionPointer &conn, char*, int, AsyncCall::Pointer &callback)
{
    fatal ("Not implemented");
}

/* should be in stub_CommRead */
#include "CommRead.h"
CommRead::CommRead(const Comm::ConnectionPointer &, char *buf, int len, AsyncCall::Pointer &callback)
{
    fatal ("Not implemented");
}

CommRead::CommRead ()
{
    fatal ("Not implemented");
}

void
commSetCloseOnExec(int fd)
{
    /* for tests... ignore */
}

#if 0
void
Comm::SetSelect(int fd, unsigned int type, PF * handler, void *client_data, time_t timeout)
{
    /* all test code runs synchronously at the moment */
}

void
Comm::QuickPollRequired()
{
    /* for tests ... ignore */
}
#endif

int
ignoreErrno(int ierrno)
{
    fatal ("Not implemented");
    return -1;
}

void
commUnsetFdTimeout(int fd)
{
    fatal ("Not implemented");
}

int
commSetNonBlocking(int fd)
{
    fatal ("Not implemented");
    return COMM_ERROR;
}

int
commUnsetNonBlocking(int fd)
{
    fatal ("Not implemented");
    return -1;
}

void
comm_init(void)
{
    fd_table =(fde *) xcalloc(Squid_MaxFD, sizeof(fde));

    /* Keep a few file descriptors free so that we don't run out of FD's
     * after accepting a client but before it opens a socket or a file.
     * Since Squid_MaxFD can be as high as several thousand, don't waste them */
    RESERVED_FD = min(100, Squid_MaxFD / 4);
}

/* MinGW needs also a stub of _comm_close() */
void
_comm_close(int fd, char const *file, int line)
{
    fatal ("Not implemented");
}

int
commSetTimeout(int fd, int timeout, AsyncCall::Pointer& callback)
{
    fatal ("Not implemented");
    return -1;
}

int
comm_open_uds(int sock_type, int proto, struct sockaddr_un* addr, int flags)
{
    fatal ("Not implemented");
    return -1;
}

void
comm_write(int fd, const char *buf, int size, AsyncCall::Pointer &callback, FREE * free_func)
{
    fatal ("Not implemented");
}
