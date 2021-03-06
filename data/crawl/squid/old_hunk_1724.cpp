                        icpIncomingConn,
                        Ipc::fdnInIcpSocket, call);

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
