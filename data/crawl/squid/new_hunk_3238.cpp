
    struct addrinfo *xai = NULL;
    int x;

    if ((port = Config.Port.icp) <= 0)
        return;

    addr = Config.Addrs.udp_incoming;
    addr.SetPort(port);

    AsyncCall::Pointer call = asyncCall(12, 2,
                                        "icpIncomingConnectionOpened",
                                        IcpListeningStartedDialer(&icpIncomingConnectionOpened, addr));

    Ipc::StartListening(SOCK_DGRAM,
                        IPPROTO_UDP,
                        addr,
                        COMM_NONBLOCKING,
                        Ipc::fdnInIcpSocket, call);

    addr.SetEmpty(); // clear for next use.
    addr = Config.Addrs.udp_outgoing;
