        calls.connector = NULL;
    }

    if (Comm::IsConnOpen(serverConn)) {
        comm_remove_close_handler(serverConnection()->fd, fwdServerClosedWrapper, this);
        debugs(17, 3, HERE << "closing FD " << serverConnection()->fd);
        serverConn->close();
    }

    serverDestinations.clear();

