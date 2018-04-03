    return newContext;
}

void
ClientSocketContext::writeControlMsg(HttpControlMsg &msg)
{
    HttpReply *rep = msg.reply;
    Must(rep);

    // apply selected clientReplyContext::buildReplyHeader() mods
    // it is not clear what headers are required for control messages
    rep->header.removeHopByHopEntries();
    rep->header.putStr(HDR_CONNECTION, "keep-alive");
    httpHdrMangleList(&rep->header, http->request, ROR_REPLY);

    // remember the callback
    cbControlMsgSent = msg.cbSuccess;

    MemBuf *mb = rep->pack();

    AsyncCall::Pointer call = commCbCall(33, 5, "ClientSocketContext::wroteControlMsg",
                                         CommIoCbPtrFun(&WroteControlMsg, this));
    comm_write_mbuf(fd(), mb, call);

    delete mb;
}

/// called when we wrote the 1xx response
void
ClientSocketContext::wroteControlMsg(int fd, char *, size_t, comm_err_t errflag, int xerrno)
{
    if (errflag == COMM_ERR_CLOSING)
        return;

    if (errflag == COMM_OK) {
        ScheduleCallHere(cbControlMsgSent);
        return;
    }

    debugs(33, 3, HERE << "1xx writing failed: " << xstrerr(xerrno));
    // no error notification: see HttpControlMsg.h for rationale and
    // note that some errors are detected elsewhere (e.g., close handler)

    // close on 1xx errors to be conservative and to simplify the code
    // (if we do not close, we must notify the source of a failure!)
    comm_close(fd);
}

/// wroteControlMsg() wrapper: ClientSocketContext is not an AsyncJob
void
ClientSocketContext::WroteControlMsg(int fd, char *bufnotused, size_t size, comm_err_t errflag, int xerrno, void *data)
{
    ClientSocketContext *context = static_cast<ClientSocketContext*>(data);
    context->wroteControlMsg(fd, bufnotused, size, errflag, xerrno);
}

#if USE_IDENT
static void
clientIdentDone(const char *ident, void *data)
