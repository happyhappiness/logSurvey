 */

#include "squid.h"
#include "base/TextException.h"
#include "CommCalls.h"
#include "comm/AcceptLimiter.h"
#include "comm/comm_internal.h"
#include "comm/Loops.h"
#include "comm/TcpAcceptor.h"
#include "ConnectionDetail.h"
#include "fde.h"
#include "protos.h"
#include "SquidTime.h"

namespace Comm {
    CBDATA_CLASS_INIT(TcpAcceptor);
};

Comm::TcpAcceptor::TcpAcceptor(const int listenFd, const Ip::Address &laddr, int flags,
                               const char *note, const Subscription::Pointer &aSub) :
        AsyncJob("Comm::TcpAcceptor"),
        errcode(0),
        fd(listenFd),
        isLimited(0),
        theCallSub(aSub),
        local_addr(laddr)
{}

void
Comm::TcpAcceptor::subscribe(const Subscription::Pointer &aSub)
{
    debugs(5, 5, HERE << status() << " AsyncCall Subscription: " << aSub);
    unsubscribe("subscription change");
    theCallSub = aSub;
}

void
Comm::TcpAcceptor::unsubscribe(const char *reason)
{
    debugs(5, 5, HERE << status() << " AsyncCall Subscription " << theCallSub << " removed: " << reason);
    theCallSub = NULL;
}

void
Comm::TcpAcceptor::start()
{
    debugs(5, 5, HERE << status() << " AsyncCall Subscription: " << theCallSub);

    Must(isOpen(fd));

    setListen();

    // if no error so far start accepting connections.
    if (errcode == 0)
        SetSelect(fd, COMM_SELECT_READ, doAccept, this, 0);
}

bool
Comm::TcpAcceptor::doneAll() const
{
    // stop when FD is closed
    if (!isOpen(fd)) {
        return AsyncJob::doneAll();
    }

    // stop when handlers are gone
    if (theCallSub == NULL) {
        return AsyncJob::doneAll();
    }

    // open FD with handlers...keep accepting.
    return false;
}

void
Comm::TcpAcceptor::swanSong()
{
    debugs(5,5, HERE);
    unsubscribe("swanSong");
    fd = -1;
    AcceptLimiter::Instance().removeDead(this);
    AsyncJob::swanSong();
}

const char *
Comm::TcpAcceptor::status() const
{
    static char ipbuf[MAX_IPSTRLEN] = {'\0'};
    if (ipbuf[0] == '\0')
        local_addr.ToHostname(ipbuf, MAX_IPSTRLEN);

    static MemBuf buf;
    buf.reset();
    buf.Printf(" FD %d, %s",fd, ipbuf);

    const char *jobStatus = AsyncJob::status();
    buf.append(jobStatus, strlen(jobStatus));

    return buf.content();
}

/**
 * New-style listen and accept routines
 *
