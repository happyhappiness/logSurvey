    Ip::Address incomingAddr = Config.Addrs.udp_incoming;
    incomingAddr.SetPort(Config.Port.htcp);

    if (!Ip::EnableIpv6 && !incomingAddr.SetIPv4()) {
        debugs(31, DBG_CRITICAL, "ERROR: IPv6 is disabled. " << incomingAddr << " is not an IPv4 address.");
        fatal("HTCP port cannot be opened.");
    }

    AsyncCall::Pointer call = asyncCall(31, 2,
                                        "htcpIncomingConnectionOpened",
                                        HtcpListeningStartedDialer(&htcpIncomingConnectionOpened));
