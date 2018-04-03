    int offset = ip->ip_hl << 2;
    AgentAddr *clt;
    AgentAddr *srv;
    fprintf (stderr, "handle_ip (ip = %p, len = %i)\n",
		    (void *) ip, len);
    if (ignore_addr.s_addr)
	if (ip->ip_src.s_addr == ignore_addr.s_addr)
	    return 0;
