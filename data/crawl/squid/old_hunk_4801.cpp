        return;
    }

    theInWccpConnection = comm_open(SOCK_DGRAM,
                                    IPPROTO_UDP,
                                    Config.Wccp.incoming,
                                    port,
                                    COMM_NONBLOCKING,
                                    "WCCP Socket");

    if (theInWccpConnection < 0)
        fatal("Cannot open WCCP Port");

    commSetSelect(theInWccpConnection,
                  COMM_SELECT_READ,
                  wccpHandleUdp,
                  NULL,
                  0);

    debug(1, 1) ("Accepting WCCP messages on port %d, FD %d.\n",
                 (int) port, theInWccpConnection);

    if (Config.Wccp.outgoing.s_addr != no_addr.s_addr) {
        theOutWccpConnection = comm_open(SOCK_DGRAM,
                                         IPPROTO_UDP,
                                         Config.Wccp.outgoing,
                                         port,
                                         COMM_NONBLOCKING,
                                         "WCCP Socket");

        if (theOutWccpConnection < 0)
            fatal("Cannot open Outgoing WCCP Port");

        commSetSelect(theOutWccpConnection,
                      COMM_SELECT_READ,
                      wccpHandleUdp,
                      NULL, 0);

        debug(1, 1) ("Outgoing WCCP messages on port %d, FD %d.\n",
                     (int) port, theOutWccpConnection);

        fd_note(theOutWccpConnection, "Outgoing WCCP socket");

        fd_note(theInWccpConnection, "Incoming WCCP socket");
    } else {
        theOutWccpConnection = theInWccpConnection;
    }

    router_len = sizeof(router);
    memset(&router, '\0', router_len);
    router.sin_family = AF_INET;
    router.sin_port = htons(port);
    router.sin_addr = Config.Wccp.router;

    if (connect(theOutWccpConnection, (struct sockaddr *) &router, router_len))
        fatal("Unable to connect WCCP out socket");

    local_len = sizeof(local);

    memset(&local, '\0', local_len);

    if (getsockname(theOutWccpConnection, (struct sockaddr *) &local, &local_len))
        fatal("Unable to getsockname on WCCP out socket");

    local_ip.s_addr = local.sin_addr.s_addr;
}

void
wccpConnectionShutdown(void)
{
    if (theInWccpConnection < 0)
        return;

    if (theInWccpConnection != theOutWccpConnection) {
        debug(80, 1) ("FD %d Closing WCCP socket\n", theInWccpConnection);
        comm_close(theInWccpConnection);
        theInWccpConnection = -1;
    }

    assert(theOutWccpConnection > -1);
    commSetSelect(theOutWccpConnection, COMM_SELECT_READ, NULL, NULL, 0);
}

void
wccpConnectionClose(void)
{
    wccpConnectionShutdown();

    if (theOutWccpConnection > -1) {
        debug(80, 1) ("FD %d Closing WCCP socket\n", theOutWccpConnection);
        comm_close(theOutWccpConnection);
    }
}

