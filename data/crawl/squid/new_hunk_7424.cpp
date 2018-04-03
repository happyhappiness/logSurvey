		theOutICPAddr = xaddr.sin_addr;
	}
    }
    if (Config.vizHack.port) {
	vizSock = comm_open(SOCK_DGRAM,
	    0,
	    any_addr,
	    0,
	    COMM_NONBLOCKING,
	    "VizHack Port");
	if (vizSock < 0)
	    fatal("Could not open Viz Socket");
#if defined(IP_ADD_MEMBERSHIP) && defined(IP_MULTICAST_TTL)
	if (Config.vizHack.addr.s_addr > inet_addr("224.0.0.0")) {
	    struct ip_mreq mr;
	    mr.imr_multiaddr.s_addr = Config.vizHack.addr.s_addr;
	    mr.imr_interface.s_addr = INADDR_ANY;
	    x = setsockopt(vizSock,
		IPPROTO_IP,
		IP_ADD_MEMBERSHIP,
		(char *) &mr,
		sizeof(struct ip_mreq));
	    if (x < 0)
		debug(5, 1, "IP_ADD_MEMBERSHIP: FD %d, addr %s: %s\n",
		    vizSock, inet_ntoa(Config.vizHack.addr), xstrerror());
	    if (setsockopt(vizSock, IPPROTO_IP, IP_MULTICAST_TTL,
		    (char *) &Config.vizHack.mcast_ttl, sizeof(char)) < 0)
		     debug(50, 1, "IP_MULTICAST_TTL: FD %d, TTL %d: %s\n",
		    vizSock, Config.vizHack.mcast_ttl, xstrerror());
	}
	memset((char *) &Config.vizHack.S, '\0', sizeof(struct sockaddr_in));
#endif
	Config.vizHack.S.sin_family = AF_INET;
	Config.vizHack.S.sin_addr = Config.vizHack.addr;
	Config.vizHack.S.sin_port = htons(Config.vizHack.port);
    }
    clientdbInit();
    icmpOpen();
    netdbInit();
