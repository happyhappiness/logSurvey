    snprintf(desc, FD_DESC_SZ, "Idle server: %s", aKey);
    fd_note(conn->fd, desc);
    debugs(48, 3, HERE << "pushed " << conn << " for " << aKey);

    // successful push notifications resume multi-connection opening sequence
    notifyManager("push");
}

Comm::ConnectionPointer
PconnPool::pop(const Comm::ConnectionPointer &dest, const char *domain, bool keepOpen)
{

    const char * aKey = key(dest, domain);

    IdleConnList *list = (IdleConnList *)hash_lookup(table, aKey);
    if (list == NULL) {
        debugs(48, 3, HERE << "lookup for key {" << aKey << "} failed.");
        // failure notifications resume standby conn creation after fdUsageHigh
        notifyManager("pop failure");
        return Comm::ConnectionPointer();
    } else {
        debugs(48, 3, HERE << "found " << hashKeyStr(&list->hash) <<
               (keepOpen ? " to use" : " to kill"));
    }

    /* may delete list */
    Comm::ConnectionPointer popped = list->findUseable(dest);
    if (!keepOpen && Comm::IsConnOpen(popped))
        popped->close();

    // successful pop notifications replenish standby connections pool
    notifyManager("pop");
    return popped;
}

void
PconnPool::notifyManager(const char *reason)
{
    if (mgr.valid())
        PeerPoolMgr::Checkpoint(mgr, reason);
}

void
PconnPool::closeN(int n)
{
    hash_table *hid = table;
    hash_first(hid);

    // close N connections, one per list, to treat all lists "fairly"
    for (int i = 0; i < n && count(); ++i) {

        hash_link *current = hash_next(hid);
        if (!current) {
            hash_first(hid);
            current = hash_next(hid);
            Must(current); // must have one because the count() was positive
        }

        // may delete current
        reinterpret_cast<IdleConnList*>(current)->closeN(1);
    }
}

void