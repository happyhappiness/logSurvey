    if (DnsSocket < 0) {
        int port;

        struct IN_ADDR addr;

        if (Config.Addrs.udp_outgoing.s_addr != no_addr.s_addr)
            addr = Config.Addrs.udp_outgoing;
        else
            addr = Config.Addrs.udp_incoming;

        DnsSocket = comm_open(SOCK_DGRAM,
                              IPPROTO_UDP,
                              addr,
                              0,
                              COMM_NONBLOCKING,
                              "DNS Socket");

        if (DnsSocket < 0)
            fatal("Could not create a DNS socket");

