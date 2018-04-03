
    Ipc::StartListening(SOCK_DGRAM,
                        IPPROTO_UDP,
                        htcpIncomingConn,
                        Ipc::fdnInHtcpSocket, call, Subscription::Pointer());

    if (!Config.Addrs.udp_outgoing.IsNoAddr()) {
        htcpOutgoingConn = new Comm::Connection;
        htcpOutgoingConn->local = Config.Addrs.udp_outgoing;
        htcpOutgoingConn->local.SetPort(Config.Port.htcp);

        if (!Ip::EnableIpv6 && !htcpOutgoingConn->local.SetIPv4()) {
            debugs(31, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << htcpOutgoingConn->local << " is not an IPv4 address.");
            fatal("HTCP port cannot be opened.");
        }
        /* split-stack for now requires default IPv4-only HTCP */
        if (Ip::EnableIpv6&IPV6_SPECIAL_SPLITSTACK && htcpOutgoingConn->local.IsAnyAddr()) {
            htcpOutgoingConn->local.SetIPv4();
        }

        enter_suid();
        comm_open_listener(SOCK_DGRAM, IPPROTO_UDP, htcpOutgoingConn, "Outgoing HTCP Socket");
        leave_suid();

        if (!Comm::IsConnOpen(htcpOutgoingConn))
            fatal("Cannot open Outgoing HTCP Socket");

        commSetSelect(htcpOutgoingConn->fd, COMM_SELECT_READ, htcpRecv, NULL, 0);

        debugs(31, DBG_IMPORTANT, "Sending HTCP messages from " << htcpOutgoingConn->local);
    }

    if (!htcpDetailPool) {
