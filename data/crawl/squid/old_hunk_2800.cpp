     */

    /* Accept a new connection */
    ConnectionDetail connDetails;
    int newfd = oldAccept(connDetails);

    /* Check for errors */
    if (newfd < 0) {

        if (newfd == COMM_NOMESSAGE) {
            /* register interest again */
            debugs(5, 5, HERE << "try later: FD " << fd << " handler: " << theCallback);
            SetSelect(fd, COMM_SELECT_READ, doAccept, this, 0);
            return;
        }

        // A non-recoverable error; notify the caller */
        debugs(5, 5, HERE << "non-recoverable error: FD " << fd << " handler: " << theCallback);
        notify(-1, COMM_ERROR, connDetails);
        mayAcceptMore = false;
        return;
    }

    debugs(5, 5, HERE << "accepted: FD " << fd <<
           " newfd: " << newfd << " from: " << connDetails.peer <<
           " handler: " << theCallback);
    notify(newfd, COMM_OK, connDetails);
}

void
Comm::ListenStateData::acceptNext()
{
    assert(isOpen(fd));
    debugs(5, 2, HERE << "connection on FD " << fd);
    acceptOne();
}

void
Comm::ListenStateData::notify(int newfd, comm_err_t flag, const ConnectionDetail &connDetails)
{
    // listener socket handlers just abandon the port with COMM_ERR_CLOSING
    // it should only happen when this object is deleted...
    if (flag == COMM_ERR_CLOSING) {
        return;
    }

    if (theCallback != NULL) {
        typedef CommAcceptCbParams Params;
        Params &params = GetCommParams<Params>(theCallback);
        params.fd = fd;
        params.nfd = newfd;
        params.details = connDetails;
        params.flag = flag;
        params.xerrno = errcode;
        ScheduleCallHere(theCallback);
        if (!mayAcceptMore)
            theCallback = NULL;
    }
}

/**
 * accept() and process
 * Wait for an incoming connection on FD.
 */
int
Comm::ListenStateData::oldAccept(ConnectionDetail &details)
{
    PROF_start(comm_accept);
    statCounter.syscalls.sock.accepts++;
