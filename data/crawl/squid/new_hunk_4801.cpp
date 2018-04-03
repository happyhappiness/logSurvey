        return;
    }

    theWccpConnection = comm_open(SOCK_DGRAM,
                                  IPPROTO_UDP,
                                  Config.Wccp.address,
                                  port,
                                  COMM_NONBLOCKING,
                                  "WCCP Socket");

    if (theWccpConnection < 0)
        fatal("Cannot open WCCP Port");

    commSetSelect(theWccpConnection,
                  COMM_SELECT_READ,
                  wccpHandleUdp,
                  NULL,
                  0);

    debug(1, 1) ("Accepting WCCP messages on port %d, FD %d.\n",
                 (int) port, theWccpConnection);


    router_len = sizeof(router);

    memset(&router, '\0', router_len);

    router.sin_family = AF_INET;

    router.sin_port = htons(port);

    router.sin_addr = Config.Wccp.router;

    if (connect(theWccpConnection, (struct sockaddr *) &router, router_len))
        fatal("Unable to connect WCCP out socket");

    local_len = sizeof(local);

    memset(&local, '\0', local_len);

    if (getsockname(theWccpConnection, (struct sockaddr *) &local, &local_len))
        fatal("Unable to getsockname on WCCP out socket");

    local_ip.s_addr = local.sin_addr.s_addr;
}


void
wccpConnectionClose(void)
{
    if (theWccpConnection > -1) {
        debug(80, 1) ("FD %d Closing WCCP socket\n", theWccpConnection);
        comm_close(theWccpConnection);
        theWccpConnection = -1;
    }
}

