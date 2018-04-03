        Ip::Address outgoingAddr = Config.Addrs.udp_outgoing;
        outgoingAddr.SetPort(Config.Port.htcp);

        enter_suid();
        htcpOutSocket = comm_open_listener(SOCK_DGRAM,
                                           IPPROTO_UDP,
