        calls.connector = NULL;
    }

    if (Comm::IsConnOpen(serverConn))
        closeServerConnection("~FwdState");

    serverDestinations.clear();

