    Ip::Address incomingAddr = Config.Addrs.udp_incoming;
    incomingAddr.SetPort(Config.Port.htcp);

    enter_suid();
    htcpInSocket = comm_open_listener(SOCK_DGRAM,
                                      IPPROTO_UDP,
                                      incomingAddr,
                                      COMM_NONBLOCKING,
                                      "HTCP Socket");
    leave_suid();

    if (htcpInSocket < 0)
        fatal("Cannot open HTCP Socket");

    commSetSelect(htcpInSocket, COMM_SELECT_READ, htcpRecv, NULL, 0);

    debugs(31, 1, "Accepting HTCP messages on port " << Config.Port.htcp << ", FD " << htcpInSocket << ".");

    if (!Config.Addrs.udp_outgoing.IsNoAddr()) {
        Ip::Address outgoingAddr = Config.Addrs.udp_outgoing;
