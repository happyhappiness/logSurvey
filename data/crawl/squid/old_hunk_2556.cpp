
    Ipc::StartListening(SOCK_DGRAM,
                        IPPROTO_UDP,
                        incomingAddr,
                        COMM_NONBLOCKING,
                        Ipc::fdnInHtcpSocket, call);

    if (!Config.Addrs.udp_outgoing.IsNoAddr()) {
        Ip::Address outgoingAddr = Config.Addrs.udp_outgoing;
        outgoingAddr.SetPort(Config.Port.htcp);

        if (!Ip::EnableIpv6 && !outgoingAddr.SetIPv4()) {
            debugs(31, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << outgoingAddr << " is not an IPv4 address.");
            fatal("HTCP port cannot be opened.");
        }
        /* split-stack for now requires default IPv4-only HTCP */
        if (Ip::EnableIpv6&IPV6_SPECIAL_SPLITSTACK && outgoingAddr.IsAnyAddr()) {
            outgoingAddr.SetIPv4();
        }

        enter_suid();
        htcpOutSocket = comm_open_listener(SOCK_DGRAM,
                                           IPPROTO_UDP,
                                           outgoingAddr,
                                           COMM_NONBLOCKING,
                                           "Outgoing HTCP Socket");
        leave_suid();

        if (htcpOutSocket < 0)
            fatal("Cannot open Outgoing HTCP Socket");

        Comm::SetSelect(htcpOutSocket, COMM_SELECT_READ, htcpRecv, NULL, 0);

        debugs(31, 1, "Outgoing HTCP messages on port " << Config.Port.htcp << ", FD " << htcpOutSocket << ".");

        fd_note(htcpInSocket, "Incoming HTCP socket");
    }

    if (!htcpDetailPool) {
