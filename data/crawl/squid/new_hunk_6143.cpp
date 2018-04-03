	    p->http_port,
	    p->icp.port);
	dump_peer_options(entry, p);
	for (d = p->peer_domain; d; d = d->next) {
	    storeAppendPrintf(entry, "cache_peer_domain %s %s%s\n",
		p->host,
		d->do_ping ? null_string : "!",
