FwdState::closeServerConnection(const char *reason)
{
    debugs(17, 3, "because " << reason << "; " << serverConn);
    comm_remove_close_handler(serverConn->fd, fwdServerClosedWrapper, this);
    fwdPconnPool->noteUses(fd_table[serverConn->fd].pconn.uses);
    serverConn->close();
}
