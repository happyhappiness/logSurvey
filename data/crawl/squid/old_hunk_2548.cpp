     */

    /* Accept a new connection */
    ConnectionDetail newConnDetails;
    int newFd = -1;
    const comm_err_t flag = oldAccept(newConnDetails, &newFd);

    /* Check for errors */
    if (!isOpen(newFd)) {

        if (flag == COMM_NOMESSAGE) {
            /* register interest again */
            debugs(5, 5, HERE << "try later: FD " << fd << " handler Subscription: " << theCallSub);
            SetSelect(fd, COMM_SELECT_READ, doAccept, this, 0);
            return;
        }

        // A non-recoverable error; notify the caller */
        debugs(5, 5, HERE << "non-recoverable error:" << status() << " handler Subscription: " << theCallSub);
        notify(flag, newConnDetails, newFd);
        mustStop("Listener socket closed");
        return;
    }

    debugs(5, 5, HERE << "Listener: FD " << fd <<
           " accepted new connection from " << newConnDetails.peer <<
           " handler Subscription: " << theCallSub);
    notify(flag, newConnDetails, newFd);
}

void
Comm::TcpAcceptor::acceptNext()
{
    Must(isOpen(fd));
    debugs(5, 2, HERE << "connection on FD " << fd);
    acceptOne();
}

// XXX: obsolete comment?
// NP: can't be a const function because syncWithComm() side effects hit theCallSub->callback().
void
Comm::TcpAcceptor::notify(const comm_err_t flag, const ConnectionDetail &connDetails, int newFd) const
{
    // listener socket handlers just abandon the port with COMM_ERR_CLOSING
    // it should only happen when this object is deleted...
