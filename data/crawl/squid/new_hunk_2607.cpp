    // should be configurable.
}

// returns a persistent or brand new connection; negative int on failures
int Adaptation::Icap::ServiceRep::getConnection(bool retriableXact, bool &reused)
{
    Ip::Address client_addr;

    int connection = theIdleConns.pop(cfg().host.termedBuf(), cfg().port, NULL, client_addr,
                                      retriableXact);

    reused = connection >= 0; // reused a persistent connection

    if (!reused) { // need a new connection
        Ip::Address outgoing;  // default: IP6_ANY_ADDR
        if (!Ip::EnableIpv6)
            outgoing.SetIPv4();
        else if (Ip::EnableIpv6&IPV6_SPECIAL_SPLITSTACK &&  !cfg().ipv6) {
            /* split-stack for now requires default IPv4-only socket */
            outgoing.SetIPv4();
        }
        connection = comm_open(SOCK_STREAM, 0, outgoing, COMM_NONBLOCKING, cfg().uri.termedBuf());
    }

    if (connection >= 0)
        ++theBusyConns;

    return connection;
}

// pools connection if it is reusable or closes it
void Adaptation::Icap::ServiceRep::putConnection(int fd, bool isReusable, const char *comment)
{
    Must(fd >= 0);
    // do not pool an idle connection if we owe connections
    if (isReusable && excessConnections() == 0) {
        debugs(93, 3, HERE << "pushing pconn" << comment);
        commSetTimeout(fd, -1, NULL, NULL);
        Ip::Address anyAddr;
        theIdleConns.push(fd, cfg().host.termedBuf(), cfg().port, NULL, anyAddr);
    } else {
        debugs(93, 3, HERE << "closing pconn" << comment);
        // comm_close will clear timeout
        comm_close(fd);
    }

    Must(theBusyConns > 0);
    --theBusyConns;
    // a connection slot released. Check if there are waiters....
    busyCheckpoint();
}

// a wrapper to avoid exposing theIdleConns
void Adaptation::Icap::ServiceRep::noteConnectionUse(int fd)
{
    Must(fd >= 0);
    fd_table[fd].noteUse(&theIdleConns);
}

void Adaptation::Icap::ServiceRep::setMaxConnections()
{
    if (cfg().maxConn >= 0)
        theMaxConnections = cfg().maxConn;
    else if (theOptions && theOptions->max_connections >= 0)
        theMaxConnections = theOptions->max_connections;
    else {
        theMaxConnections = -1;
        return;
    }

    if (::Config.workers > 1 )
        theMaxConnections /= ::Config.workers;
}

int Adaptation::Icap::ServiceRep::availableConnections() const
{
    if (theMaxConnections < 0)
        return -1;

    // we are available if we can open or reuse connections
    // in other words, if we will not create debt
    int available = max(0, theMaxConnections - theBusyConns);

    if (!available && !connOverloadReported) {
        debugs(93, DBG_IMPORTANT, "WARNING: ICAP Max-Connections limit " <<
               "exceeded for service " << cfg().uri << ". Open connections now: " <<
               theBusyConns + theIdleConns.count() << ", including " <<
               theIdleConns.count() << " idle persistent connections.");
        connOverloadReported = true;
    }

    if (cfg().onOverload == srvForce)
        return -1;

    return available;
}

// The number of connections which excess the Max-Connections limit
int Adaptation::Icap::ServiceRep::excessConnections() const
{
    if (theMaxConnections < 0)
        return 0;

    // Waiters affect the number of needed connections but a needed
    // connection may still be excessive from Max-Connections p.o.v.
    // so we should not account for waiting transaction needs here.
    const int debt =  theBusyConns + theIdleConns.count() - theMaxConnections;
    if (debt > 0)
        return debt;
    else
        return 0;
}

void Adaptation::Icap::ServiceRep::noteGoneWaiter()
{
    theAllWaiters--;

    // in case the notified transaction did not take the connection slot
    busyCheckpoint();
}

// called when a connection slot may become available
void Adaptation::Icap::ServiceRep::busyCheckpoint()
{
    if (theNotificationWaiters.empty()) // nobody is waiting for a slot
        return;

    int freed = 0;
    int available = availableConnections();

    if (available < 0) {
        // It is possible to have waiters when no limit on connections exist in
        // case of reconfigure or because new Options received.
        // In this case, notify all waiting transactions.
        freed  = theNotificationWaiters.size();
    } else {
        // avoid notifying more waiters than there will be available slots
        const int notifiedWaiters = theAllWaiters - theNotificationWaiters.size();
        freed = available - notifiedWaiters;
    }

    debugs(93,7, HERE << "Available connections: " << available <<
           " freed slots: " << freed <<
           " waiting in queue: " << theNotificationWaiters.size());

    while (freed > 0 && !theNotificationWaiters.empty()) {
        Client i = theNotificationWaiters.front();
        theNotificationWaiters.pop_front();
        ScheduleCallHere(i.callback);
        i.callback = NULL;
        --freed;
    }
}

void Adaptation::Icap::ServiceRep::suspend(const char *reason)
{
    if (isSuspended) {