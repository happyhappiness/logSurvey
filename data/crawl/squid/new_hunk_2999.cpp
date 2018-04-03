icpConnectionsOpen(void)
{
    uint16_t port;
//    Ip::Address addr;

    if ((port = Config.Port.icp) <= 0)
        return;

    icpIncomingConn = new Comm::Connection;
    icpIncomingConn->local = Config.Addrs.udp_incoming;
    icpIncomingConn->local.SetPort(port);

    if (!Ip::EnableIpv6 && !icpIncomingConn->local.SetIPv4()) {
        debugs(12, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << icpIncomingConn->local << " is not an IPv4 address.");
        fatal("ICP port cannot be opened.");
    }
    /* split-stack for now requires default IPv4-only ICP */
    if (Ip::EnableIpv6&IPV6_SPECIAL_SPLITSTACK && icpIncomingConn->local.IsAnyAddr()) {
        icpIncomingConn->local.SetIPv4();
    }

    AsyncCall::Pointer call = asyncCall(12, 2,
                                        "icpIncomingConnectionOpened",
                                        IcpListeningStartedDialer(&icpIncomingConnectionOpened));

    Ipc::StartListening(SOCK_DGRAM,
                        IPPROTO_UDP,
                        icpIncomingConn,
                        Ipc::fdnInIcpSocket, call, Subscription::Pointer());

    if ( !Config.Addrs.udp_outgoing.IsNoAddr() ) {
        icpOutgoingConn = new Comm::Connection;
        icpOutgoingConn->local = Config.Addrs.udp_outgoing;
        icpOutgoingConn->local.SetPort(port);

        if (!Ip::EnableIpv6 && !icpOutgoingConn->local.SetIPv4()) {
            debugs(49, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << icpOutgoingConn->local << " is not an IPv4 address.");
            fatal("ICP port cannot be opened.");
        }
        /* split-stack for now requires default IPv4-only ICP */
        if (Ip::EnableIpv6&IPV6_SPECIAL_SPLITSTACK && icpOutgoingConn->local.IsAnyAddr()) {
            icpOutgoingConn->local.SetIPv4();
        }

        enter_suid();
        comm_open_listener(SOCK_DGRAM, IPPROTO_UDP, icpOutgoingConn, "Outgoing ICP Port");
        leave_suid();

        if (!Comm::IsConnOpen(icpOutgoingConn))
            fatal("Cannot open Outgoing ICP Port");

        debugs(12, DBG_CRITICAL, "Sending ICP messages from " << icpOutgoingConn->local);

        commSetSelect(icpOutgoingConn->fd, COMM_SELECT_READ, icpHandleUdp, NULL, 0);
    }

    // Ensure that we have the IP address(es) to use for Host ID.
    // The outgoing address is used as 'private' host ID used only on packets we send
    struct addrinfo *xai = NULL;
    theIcpPrivateHostID.InitAddrInfo(xai);
    if (getsockname(icpOutgoingConn->fd, xai->ai_addr, &xai->ai_addrlen) < 0)
        debugs(50, DBG_IMPORTANT, "ERROR: Unable to identify ICP host ID to use for " << icpOutgoingConn
               << ": getsockname: " << xstrerror());
    else
        theIcpPrivateHostID = *xai;
    theIcpPrivateHostID.FreeAddrInfo(xai);
}

static void
icpIncomingConnectionOpened(int errNo)
{
    if (!Comm::IsConnOpen(icpIncomingConn))
        fatal("Cannot open ICP Port");

    commSetSelect(icpIncomingConn->fd, COMM_SELECT_READ, icpHandleUdp, NULL, 0);

    for (const wordlist *s = Config.mcast_group_list; s; s = s->next)
        ipcache_nbgethostbyname(s->key, mcastJoinGroups, NULL); // XXX: pass the icpIncomingConn for mcastJoinGroups usage.

    debugs(12, DBG_IMPORTANT, "Accepting ICP messages on " << icpIncomingConn->local);

    fd_note(icpIncomingConn->fd, "Incoming ICP port");

    if (Config.Addrs.udp_outgoing.IsNoAddr()) {
        icpOutgoingConn = icpIncomingConn;
        debugs(12, DBG_IMPORTANT, "Sending ICP messages from " << icpOutgoingConn->local);
    }

    // Ensure that we have the IP address(es) to use for Host ID.
    // The listening address is used as 'public' host ID which can be used to contact us
    struct addrinfo *xai = NULL;
    theIcpPublicHostID.InitAddrInfo(xai); // reset xai
    if (getsockname(icpIncomingConn->fd, xai->ai_addr, &xai->ai_addrlen) < 0)
        debugs(50, DBG_IMPORTANT, "ERROR: Unable to identify ICP host ID to use for " << icpIncomingConn
               << ": getsockname: " << xstrerror());
    else
        theIcpPublicHostID = *xai;
    theIcpPublicHostID.FreeAddrInfo(xai);
}

/**
