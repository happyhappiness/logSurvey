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
