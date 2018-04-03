	} else if (!strcasecmp(token, "no-netdb-exchange")) {
	    p->options.no_netdb_exchange = 1;
#if USE_CARP
	} else if (!strcasecmp(token, "carp")) {
	    if (p->type != PEER_PARENT)
		fatalf("parse_peer: non-parent carp peer %s/%d\n", p->host, p->http_port);
	    p->options.carp = 1;
#endif
#if DELAY_POOLS
	} else if (!strcasecmp(token, "no-delay")) {
