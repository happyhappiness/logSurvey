 * of requests JUST as they timeout (say, it shuts down) we'll be wasting
 * quite a bit of CPU. Just keep it in mind.
 */
Comm::ConnectionPointer
IdleConnList::findUseable(const Comm::ConnectionPointer &key)
{
    assert(size_);

    // small optimization: do the constant bool tests only once.
    const bool keyCheckAddr = !key->local.IsAnyAddr();
    const bool keyCheckPort = key->local.GetPort() > 0;

    for (int i=size_-1; i>=0; i--) {

        // Is the FD pending completion of the closure callback?
        // this flag is set while our early-read/close handler is
        // waiting for a remote response. It gets unset when the
        // handler is scheduled.
        if (!fd_table[theList_[i]->fd].flags.read_pending)
            continue;

        // connection already closed. useless.
        if (!Comm::IsConnOpen(theList_[i]))
            continue;

        // local end port is required, but dont match.
        if (keyCheckPort && key->local.GetPort() != theList_[i]->local.GetPort())
            continue;

        // local address is required, but does not match.
        if (keyCheckAddr && key->local.matchIPAddr(theList_[i]->local) != 0)
            continue;

        // finally, a match. pop and return it.
        Comm::ConnectionPointer result = theList_[i];
        /* may delete this */
        removeAt(i);
        return result;
    }

    return Comm::ConnectionPointer();
}

void
IdleConnList::Read(const Comm::ConnectionPointer &conn, char *buf, size_t len, comm_err_t flag, int xerrno, void *data)
{
    debugs(48, 3, HERE << len << " bytes from " << conn);

    if (flag == COMM_ERR_CLOSING) {
        /* Bail out early on COMM_ERR_CLOSING - close handlers will tidy up for us */
        return;
    }

    IdleConnList *list = (IdleConnList *) data;
    int index = list->findIndexOf(conn);
    if (index >= 0) {
        /* might delete list */
        list->removeAt(index);
        list->clearHandlers(conn);
    }
    // else we lost a race.
    // Somebody started using the pconn since the remote end disconnected.
    // pass the closure info on!
    conn->close();
}

void
IdleConnList::Timeout(const CommTimeoutCbParams &io)
{
    debugs(48, 3, HERE << io.conn);
    IdleConnList *list = static_cast<IdleConnList *>(io.data);
    int index = list->findIndexOf(io.conn);
    if (index >= 0) {
        /* might delete list */
        list->removeAt(index);
        io.conn->close();
    }
}

/* ========== PconnPool PRIVATE FUNCTIONS ============================================ */

const char *
PconnPool::key(const Comm::ConnectionPointer &destLink, const char *domain)
{
    LOCAL_ARRAY(char, buf, SQUIDHOSTNAMELEN * 3 + 10);

    destLink->remote.ToURL(buf, SQUIDHOSTNAMELEN * 3 + 10);
    if (domain) {
        const int used = strlen(buf);
        snprintf(buf+used, SQUIDHOSTNAMELEN * 3 + 10-used, "/%s", domain);
    }

    debugs(48,6,"PconnPool::key(" << destLink << ", " << (domain?domain:"[no domain]") << ") is {" << buf << "}" );
    return buf;
}

void
PconnPool::dumpHist(StoreEntry * e) const
{
    storeAppendPrintf(e,
                      "%s persistent connection counts:\n"
                      "\n"
