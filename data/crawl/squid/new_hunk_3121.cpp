    if (DnsSocketA < 0 && DnsSocketB < 0) {
        int port;

        Ip::Address addrA; // since we don't want to alter Config.Addrs.udp_* and dont have one of our own.

        if (!Config.Addrs.udp_outgoing.IsNoAddr())
            addrA = Config.Addrs.udp_outgoing;
        else
            addrA = Config.Addrs.udp_incoming;

        Ip::Address addrB = addrA;
        addrA.SetIPv4();

        if (Ip::EnableIpv6 && (addrB.IsAnyAddr() || addrB.IsIPv6())) {
            debugs(78, 2, "idnsInit: attempt open DNS socket to: " << addrB);
            DnsSocketB = comm_open_listener(SOCK_DGRAM,
                                            IPPROTO_UDP,
                                            addrB,
                                            COMM_NONBLOCKING,
                                            "DNS Socket IPv6");
        }

        if (addrA.IsAnyAddr() || addrA.IsIPv4()) {
            debugs(78, 2, "idnsInit: attempt open DNS socket to: " << addrA);
            DnsSocketA = comm_open_listener(SOCK_DGRAM,
                                            IPPROTO_UDP,
                                            addrA,
                                            COMM_NONBLOCKING,
                                            "DNS Socket IPv4");
        }

        if (DnsSocketA < 0 && DnsSocketB < 0)
            fatal("Could not create a DNS socket");

        /* Ouch... we can't call functions using debug from a debug
         * statement. Doing so messes up the internal Debug::level
         */
        if (DnsSocketB >= 0) {
            port = comm_local_port(DnsSocketB);
            debugs(78, 1, "DNS Socket created at " << addrB << ", FD " << DnsSocketB);
        }
        if (DnsSocketA >= 0) {
            port = comm_local_port(DnsSocketA);
            debugs(78, 1, "DNS Socket created at " << addrA << ", FD " << DnsSocketA);
        }
    }

