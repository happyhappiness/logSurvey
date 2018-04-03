    if (errflag == COMM_ERR_CLOSING)
        return;

    assert (Comm::IsConnOpen(http->getConn()->clientConn) && this->fd() == aFileDescriptor);

    if (errflag || clientHttpRequestStatus(aFileDescriptor, http)) {
        initiateClose("failure or true request status");
        /* Do we leak here ? */
        return;
