    // should be configurable.
}

// returns a persistent or brand new connection; negative int on failures
Comm::ConnectionPointer
Adaptation::Icap::ServiceRep::getConnection(bool retriableXact, bool &reused)
{
    Comm::ConnectionPointer connection = new Comm::Connection;

    /* NP: set these here because it applies whether a pconn or a new conn is used */

    // TODO: Avoid blocking lookup if s.cfg().host is a hostname
    connection->remote = cfg().host.termedBuf();
    connection->remote.SetPort(cfg().port);

    // TODO: check whether NULL domain is appropriate here
    theIdleConns.pop(connection, NULL, retriableXact);
    reused = connection->isOpen(); // reused a persistent connection

    if (reused)
        debugs(93,3, HERE << "reused pconn " << connection);
    // else, return unopened Comm::Connection for caller to open.

    if (connection->isOpen())
        ++theBusyConns;

    return connection;
}

// pools connection if it is reusable or closes it
void Adaptation::Icap::ServiceRep::putConnection(const Comm::ConnectionPointer &conn, bool isReusable, const char *comment)
{
    Must(Comm::IsConnOpen(conn));
    // do not pool an idle connection if we owe connections
    if (isReusable && excessConnections() == 0) {
        debugs(93, 3, HERE << "pushing pconn" << comment);
        commUnsetConnTimeout(conn);
        theIdleConns.push(conn, NULL);
    } else {
        debugs(93, 3, HERE << "closing pconn" << comment);
        // comm_close will clear timeout
        conn->close();
    }

    Must(theBusyConns > 0);
    --theBusyConns;
    // a connection slot released. Check if there are waiters....
    busyCheckpoint();
}

// a wrapper to avoid exposing theIdleConns
void Adaptation::Icap::ServiceRep::noteConnectionUse(const Comm::ConnectionPointer &conn)
{
    Must(Comm::IsConnOpen(conn));
    fd_table[conn->fd].noteUse(&theIdleConns);
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
