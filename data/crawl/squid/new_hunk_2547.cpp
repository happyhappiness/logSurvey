{
    debugs(5,5, HERE);
    unsubscribe("swanSong");
    conn = NULL;
    AcceptLimiter::Instance().removeDead(this);
    AsyncJob::swanSong();
}

const char *
Comm::TcpAcceptor::status() const
{
    if (conn == NULL)
        return "[nil connection]";

    static char ipbuf[MAX_IPSTRLEN] = {'\0'};
    if (ipbuf[0] == '\0')
        conn->local.ToHostname(ipbuf, MAX_IPSTRLEN);

    static MemBuf buf;
    buf.reset();
    buf.Printf(" FD %d, %s",conn->fd, ipbuf);

    const char *jobStatus = AsyncJob::status();
    buf.append(jobStatus, strlen(jobStatus));
