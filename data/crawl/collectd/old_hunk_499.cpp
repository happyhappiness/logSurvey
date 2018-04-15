    int offset = ip->ip_hl << 2;
    AgentAddr *clt;
    AgentAddr *srv;
    if (ignore_addr.s_addr)
	if (ip->ip_src.s_addr == ignore_addr.s_addr)
	    return 0;
