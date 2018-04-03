}

void
Mgr::Forwarder::start()
{
    debugs(16, 3, HERE);
    entry->registerAbort(&Forwarder::Abort, this);

    typedef NullaryMemFunT<Mgr::Forwarder> Dialer;
    AsyncCall::Pointer callback = JobCallback(16, 5, Dialer, this,
                                  Forwarder::handleRemoteAck);
    if (++LastRequestId == 0) // don't use zero value as requestId
        ++LastRequestId;
    requestId = LastRequestId;
    TheRequestsMap[requestId] = callback;
    Request mgrRequest(KidIdentifier, requestId, fd, params);
    Ipc::TypedMsgHdr message;

    try {
        mgrRequest.pack(message);
    } catch (...) {
        // assume the pack() call failed because the message did not fit
        // TODO: add a more specific exception?
        debugs(16, DBG_CRITICAL, "ERROR: uri " << entry->url() << " exceeds buffer size");
        quitOnError("long URI", errorCon(ERR_INVALID_URL, HTTP_REQUEST_URI_TOO_LARGE, request));
    }

    Ipc::SendMessage(Ipc::coordinatorAddr, message);
    const double timeout = 10; // in seconds
    eventAdd("Mgr::Forwarder::requestTimedOut", &Forwarder::RequestTimedOut,
             this, timeout, 0, false);
}

void
Mgr::Forwarder::swanSong()
{
    debugs(16, 5, HERE);
    removeTimeoutEvent();
    if (requestId > 0) {
        DequeueRequest(requestId);
        requestId = 0;
    }
    close();
}

bool
Mgr::Forwarder::doneAll() const
{
    debugs(16, 5, HERE);
    return requestId == 0;
}

/// called when the client socket gets closed by some external force
void
Mgr::Forwarder::noteCommClosed(const CommCloseCbParams &io)
{
    debugs(16, 5, HERE);
    Must(fd == io.fd);
    fd = -1;
    mustStop("commClosed");
}
