        return true;
    }

    conn->close();
    return false;
}

/**
 *
 * \retval 1 on success
 * \retval 0 when needs more data
 * \retval -1 on error
 */
static int
Squid_SSL_accept(ConnStateData *conn, PF *callback)
{
    int fd = conn->clientConnection->fd;
    auto ssl = fd_table[fd].ssl.get();
    int ret;

    errno = 0;
    if ((ret = SSL_accept(ssl)) <= 0) {
        const int xerrno = errno;
        const int ssl_error = SSL_get_error(ssl, ret);

        switch (ssl_error) {

        case SSL_ERROR_WANT_READ:
            Comm::SetSelect(fd, COMM_SELECT_READ, callback, (callback != NULL ? conn : NULL), 0);
            return 0;

        case SSL_ERROR_WANT_WRITE:
            Comm::SetSelect(fd, COMM_SELECT_WRITE, callback, (callback != NULL ? conn : NULL), 0);
            return 0;

        case SSL_ERROR_SYSCALL:
            if (ret == 0) {
                debugs(83, 2, "Error negotiating SSL connection on FD " << fd << ": Aborted by client: " << ssl_error);
            } else {
                debugs(83, (xerrno == ECONNRESET) ? 1 : 2, "Error negotiating SSL connection on FD " << fd << ": " <<
                       (xerrno == 0 ? Security::ErrorString(ssl_error) : xstrerr(xerrno)));
            }
            return -1;

        case SSL_ERROR_ZERO_RETURN:
            debugs(83, DBG_IMPORTANT, "Error negotiating SSL connection on FD " << fd << ": Closed by client");
            return -1;

        default:
            debugs(83, DBG_IMPORTANT, "Error negotiating SSL connection on FD " <<
                   fd << ": " << Security::ErrorString(ERR_get_error()) <<
                   " (" << ssl_error << "/" << ret << ")");
            return -1;
        }

        /* NOTREACHED */
    }
    return 1;
}

/** negotiate an SSL connection */
static void
clientNegotiateSSL(int fd, void *data)
{
    ConnStateData *conn = (ConnStateData *)data;
    int ret;
    if ((ret = Squid_SSL_accept(conn, clientNegotiateSSL)) <= 0) {
        if (ret < 0) // An error
            conn->clientConnection->close();
        return;
    }

    Security::SessionPointer session(fd_table[fd].ssl);
    if (Security::SessionIsResumed(session)) {
        debugs(83, 2, "Session " << SSL_get_session(session.get()) <<
               " reused on FD " << fd << " (" << fd_table[fd].ipaddr <<
