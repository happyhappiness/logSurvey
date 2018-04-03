    if (DnsSocket < 0) {
        int port;

        IpAddress addr; // since we don't want to alter Config.Addrs.udp_* and dont have one of our own.

        if (!Config.Addrs.udp_outgoing.IsNoAddr())
            addr = Config.Addrs.udp_outgoing;
        else
            addr = Config.Addrs.udp_incoming;

        debugs(78, 2, "idnsInit: attempt open DNS socket to: " << addr);
        DnsSocket = comm_open_listener(SOCK_DGRAM,
                              IPPROTO_UDP,
                              addr,
                              COMM_NONBLOCKING,
                              "DNS Socket");

        if (DnsSocket < 0)
            fatal("Could not create a DNS socket");

