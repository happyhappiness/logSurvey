    Ip::Address incomingAddr = Config.Addrs.udp_incoming;
    incomingAddr.SetPort(Config.Port.htcp);

    AsyncCall::Pointer call = asyncCall(31, 2,
                                        "htcpIncomingConnectionOpened",
                                        HtcpListeningStartedDialer(&htcpIncomingConnectionOpened));

    Ipc::StartListening(SOCK_DGRAM,
                        IPPROTO_UDP,
                        incomingAddr,
                        COMM_NONBLOCKING,
                        Ipc::fdnInHtcpSocket, call);

    if (!Config.Addrs.udp_outgoing.IsNoAddr()) {
        Ip::Address outgoingAddr = Config.Addrs.udp_outgoing;
