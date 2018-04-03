}

void
Mgr::Forwarder::handleError()
{
    debugs(16, DBG_CRITICAL, "ERROR: uri " << entry->url() << " exceeds buffer size");
    sendError(errorCon(ERR_INVALID_URL, HTTP_REQUEST_URI_TOO_LARGE, httpRequest));
    mustStop("long URI");
}

void
Mgr::Forwarder::handleTimeout()
{
    sendError(errorCon(ERR_LIFETIME_EXP, HTTP_REQUEST_TIMEOUT, httpRequest));
    Ipc::Forwarder::handleTimeout();
}

void
Mgr::Forwarder::handleException(const std::exception& e)
{
    if (entry != NULL && httpRequest != NULL && fd >= 0)
        sendError(errorCon(ERR_INVALID_RESP, HTTP_INTERNAL_SERVER_ERROR, httpRequest));
    Ipc::Forwarder::handleException(e);
}

/// called when the client socket gets closed by some external force
void
Mgr::Forwarder::noteCommClosed(const CommCloseCbParams& params)
{
    debugs(16, 5, HERE);
    Must(fd == params.fd);
    fd = -1;
    mustStop("commClosed");
}
