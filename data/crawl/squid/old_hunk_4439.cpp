                  NULL,
                  0);

    debugs(80, 1, "Accepting WCCPv1 messages on port " << port << ", FD " << theWccpConnection << ".");


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


