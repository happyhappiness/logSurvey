	    neighborTypeStr(p),
	    p->http_port,
	    p->icp_port);
	dump_peer_options(entry, p);
	p = p->next;
    }
}
