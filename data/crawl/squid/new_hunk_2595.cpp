
    debugs(80, 1, "Accepting WCCPv1 messages on " << Config.Wccp.address << ", FD " << theWccpConnection << ".");


    // Sadly WCCP only does IPv4

    struct sockaddr_in router;
    Config.Wccp.router.GetSockAddr(router);
    if (connect(theWccpConnection, (struct sockaddr*)&router, sizeof(router)))
        fatal("Unable to connect WCCP out socket");

    struct sockaddr_in local;
    memset(&local, '\0', sizeof(local));
    socklen_t slen = sizeof(local);
    if (getsockname(theWccpConnection, (struct sockaddr*)&local, &slen))
        fatal("Unable to getsockname on WCCP out socket");

    local_ip = local;
}


