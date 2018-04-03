 *
 */

#include "config.h"
#include "comm.h"
#include "comm/Connection.h"
#include "comm/Loops.h"
#include "fde.h"

#define STUB_API "comm.cc"
#include "tests/STUB.h"

void comm_read(const Comm::ConnectionPointer &conn, char *buf, int size, IOCB *handler, void *handler_data) STUB
void comm_read(const Comm::ConnectionPointer &conn, char*, int, AsyncCall::Pointer &callback) STUB

/* should be in stub_CommRead */
#include "CommRead.h"
CommRead::CommRead(const Comm::ConnectionPointer &, char *buf, int len, AsyncCall::Pointer &callback) STUB
CommRead::CommRead() STUB
DeferredReadManager::~DeferredReadManager() STUB
DeferredRead::DeferredRead(DeferrableRead *, void *, CommRead const &) STUB
void DeferredReadManager::delayRead(DeferredRead const &aRead) STUB
void DeferredReadManager::kickReads(int const count) STUB

void commSetCloseOnExec(int fd) STUB_NOP
int ignoreErrno(int ierrno) STUB_RETVAL(-1)

void commUnsetFdTimeout(int fd) STUB
int commSetNonBlocking(int fd) STUB_RETVAL(COMM_ERROR)
int commUnsetNonBlocking(int fd) STUB_RETVAL(-1)

// MinGW needs also a stub of _comm_close()
void _comm_close(int fd, char const *file, int line) STUB
int commSetTimeout(int fd, int timeout, AsyncCall::Pointer& callback) STUB_RETVAL(-1)
int comm_open_uds(int sock_type, int proto, struct sockaddr_un* addr, int flags) STUB_RETVAL(-1)
void comm_write(int fd, const char *buf, int size, AsyncCall::Pointer &callback, FREE * free_func) STUB