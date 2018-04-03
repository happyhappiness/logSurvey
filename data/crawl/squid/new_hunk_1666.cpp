
    if (!valid) {
        /* The pinning info is not safe, remove any pinning info */
        unpinConnection(true);
    }

    return pinning.serverConnection;
}

Comm::ConnectionPointer
ConnStateData::borrowPinnedConnection(HttpRequest *request, const CachePeer *aPeer)
{
    debugs(33, 7, pinning.serverConnection);
    if (validatePinnedConnection(request, aPeer) != NULL)
        stopMonitoringPinnedConnection();

    return pinning.serverConnection; // closed if validation failed
}

/// [re]start monitoring pinned connection for server closures so that we can
/// propagate them to an _idle_ client pinned to the server
void
ConnStateData::startMonitoringPinnedConnection()
{
    if (!pinning.reading) {
         pinning.reading = true;
         Comm::SetSelect(pinning.serverConnection->fd, COMM_SELECT_READ,
                         &ConnStateData::ReadPinnedConnection,
                         new Pointer(this), 0);
    }
}

/// stop or suspend monitoring pinned connection for server closures
void
ConnStateData::stopMonitoringPinnedConnection()
{
    if (pinning.reading) {
         Comm::SetSelect(pinning.serverConnection->fd, COMM_SELECT_READ, NULL, NULL, 0);
         pinning.reading = false;
    }
}

/// read callback for the idle pinned server connection
void
ConnStateData::ReadPinnedConnection(int fd, void *data)
{
    Pointer *ptr = static_cast<Pointer*>(data);
    if (ConnStateData *client = dynamic_cast<ConnStateData*>(ptr->valid())) {
        // get back inside job call protection
        typedef NullaryMemFunT<ConnStateData> Dialer;
        AsyncCall::Pointer call = JobCallback(33, 5, Dialer, client,
                                              ConnStateData::readPinnedConnection);
        ScheduleCallHere(call);
    }
    delete ptr;
}

void
ConnStateData::readPinnedConnection()
{
    pinning.reading = false; // select loop clears our subscription before cb
    mustStop("suspected pinned server eof");
}

void
ConnStateData::unpinConnection(const bool andClose)
{
    debugs(33, 3, HERE << pinning.serverConnection);

