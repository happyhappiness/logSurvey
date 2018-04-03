     */

    /* Accept a new connection */
    ConnectionPointer newConnDetails = new Connection();
    const comm_err_t flag = oldAccept(newConnDetails);

    /* Check for errors */
    if (!newConnDetails->isOpen()) {

        if (flag == COMM_NOMESSAGE) {
            /* register interest again */
            debugs(5, 5, HERE << "try later: " << conn << " handler Subscription: " << theCallSub);
            SetSelect(conn->fd, COMM_SELECT_READ, doAccept, this, 0);
            return;
        }

        // A non-recoverable error; notify the caller */
        debugs(5, 5, HERE << "non-recoverable error:" << status() << " handler Subscription: " << theCallSub);
        notify(flag, newConnDetails);
        mustStop("Listener socket closed");
        return;
    }

    debugs(5, 5, HERE << "Listener: " << conn <<
           " accepted new connection " << newConnDetails <<
           " handler Subscription: " << theCallSub);
    notify(flag, newConnDetails);
}

void
Comm::TcpAcceptor::acceptNext()
{
    Must(IsConnOpen(conn));
    debugs(5, 2, HERE << "connection on " << conn);
    acceptOne();
}

void
Comm::TcpAcceptor::notify(const comm_err_t flag, const Comm::ConnectionPointer &newConnDetails) const
{
    // listener socket handlers just abandon the port with COMM_ERR_CLOSING
    // it should only happen when this object is deleted...
