
    struct addrinfo *xai = NULL;
    int x;
    wordlist *s;

    if ((port = Config.Port.icp) <= 0)
        return;

    enter_suid();

    addr = Config.Addrs.udp_incoming;
    addr.SetPort(port);
    theInIcpConnection = comm_open_listener(SOCK_DGRAM,
                                            IPPROTO_UDP,
                                            addr,
                                            COMM_NONBLOCKING,
                                            "ICP Socket");
    leave_suid();

    if (theInIcpConnection < 0)
        fatal("Cannot open ICP Port");

    commSetSelect(theInIcpConnection,
                  COMM_SELECT_READ,
                  icpHandleUdp,
                  NULL,
                  0);

    for (s = Config.mcast_group_list; s; s = s->next)
        ipcache_nbgethostbyname(s->key, mcastJoinGroups, NULL);

    debugs(12, 1, "Accepting ICP messages at " << addr << ", FD " << theInIcpConnection << ".");

    addr.SetEmpty(); // clear for next use.
    addr = Config.Addrs.udp_outgoing;
