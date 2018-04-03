 * of requests JUST as they timeout (say, it shuts down) we'll be wasting
 * quite a bit of CPU. Just keep it in mind.
 */
int
IdleConnList::findUseableFD()
{
    assert(nfds);

    for (int i=nfds-1; i>=0; i--) {
        if (!comm_has_pending_read_callback(fds[i])) {
            return fds[i];
        }
    }

    return -1;
}

void
IdleConnList::read(int fd, char *buf, size_t len, comm_err_t flag, int xerrno, void *data)
{
    debugs(48, 3, "IdleConnList::read: " << len << " bytes from FD " << fd);

    if (flag == COMM_ERR_CLOSING) {
        /* Bail out early on COMM_ERR_CLOSING - close handlers will tidy up for us */
        return;
    }

    IdleConnList *list = (IdleConnList *) data;
    list->removeFD(fd);	/* might delete list */
    comm_close(fd);
}

void
IdleConnList::timeout(int fd, void *data)
{
    debugs(48, 3, "IdleConnList::timeout: FD " << fd);
    IdleConnList *list = (IdleConnList *) data;
    list->removeFD(fd);	/* might delete list */
    comm_close(fd);
}

/* ========== PconnPool PRIVATE FUNCTIONS ============================================ */

const char *
PconnPool::key(const char *host, u_short port, const char *domain, Ip::Address &client_address)
{
    LOCAL_ARRAY(char, buf, SQUIDHOSTNAMELEN * 3 + 10);
    char ntoabuf[MAX_IPSTRLEN];

    if (domain && !client_address.IsAnyAddr())
        snprintf(buf, SQUIDHOSTNAMELEN * 3 + 10, "%s:%d-%s/%s", host, (int) port, client_address.NtoA(ntoabuf,MAX_IPSTRLEN), domain);
    else if (domain && client_address.IsAnyAddr())
        snprintf(buf, SQUIDHOSTNAMELEN * 3 + 10, "%s:%d/%s", host, (int) port, domain);
    else if ((!domain) && !client_address.IsAnyAddr())
        snprintf(buf, SQUIDHOSTNAMELEN * 3 + 10, "%s:%d-%s", host, (int) port, client_address.NtoA(ntoabuf,MAX_IPSTRLEN));
    else
        snprintf(buf, SQUIDHOSTNAMELEN * 3 + 10, "%s:%d", host, (int) port);

    debugs(48,6,"PconnPool::key(" << (host?host:"(no host!)") << "," << port << "," << (domain?domain:"(no domain)") << "," << client_address << "is {" << buf << "}" );
    return buf;
}

void
PconnPool::dumpHist(StoreEntry * e)
{
    int i;
    storeAppendPrintf(e,
                      "%s persistent connection counts:\n"
                      "\n"
