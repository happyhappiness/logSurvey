    addr = Config.Addrs.udp_incoming;
    addr.SetPort(port);

    AsyncCall::Pointer call = asyncCall(12, 2,
                                        "icpIncomingConnectionOpened",
                                        IcpListeningStartedDialer(&icpIncomingConnectionOpened, addr));
